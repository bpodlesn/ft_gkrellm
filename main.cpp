/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:41:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 15:19:19 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/sysctl.h>
#include <ctime>
#include <mach/mach_host.h>
#include <mach/processor_info.h>
#include <fstream>

class CpuUsage {
 public:
  CpuUsage(int core): core_(core) {
    prev = updated_ticks_(core);
  }
 
  float get() {
    Ticks t = updated_ticks_(core_);
    unsigned long long int used = t.used() - prev.used();
    unsigned long long int total = t.total() - prev.total();
    prev = t;
    return (float)used / (float)total * 100.0f;
  }
 
 private:
  struct Ticks {
    unsigned long long int usertime;
    unsigned long long int nicetime;
    unsigned long long int systemtime;
    unsigned long long int idletime;
 
    unsigned long long int used() { return usertime + nicetime + systemtime; }
    unsigned long long int total() { return usertime + nicetime + systemtime + idletime; }
  } prev;
 
  int core_;
 
  Ticks updated_ticks_(int core) {
    unsigned int cpu_count;
    processor_cpu_load_info_t cpu_load;
    mach_msg_type_number_t cpu_msg_count;
 
    int rc =  host_processor_info(
      mach_host_self( ),
      PROCESSOR_CPU_LOAD_INFO,
      &cpu_count,
      (processor_info_array_t *) &cpu_load,
      &cpu_msg_count
    );
    if (rc != 0) {
      printf("Error: failed to scan processor info (rc=%d)\n", rc);
      exit(1);
    }
 
    if (core < 0 || cpu_count <= core) {
      printf("Error: invalid core number: %d\n", core);
      exit(1);
    }
    unsigned long long int usertime = cpu_load[core].cpu_ticks[CPU_STATE_USER];
    unsigned long long int nicetime = cpu_load[core].cpu_ticks[CPU_STATE_NICE];
    unsigned long long int systemtime = cpu_load[core].cpu_ticks[CPU_STATE_SYSTEM];
    unsigned long long int idletime = cpu_load[core].cpu_ticks[CPU_STATE_IDLE];
 
    Ticks t = {usertime, nicetime, systemtime, idletime};
    return t;
  }
 
};


int	main(){

	//hostname and username
	char hostname[_SC_HOST_NAME_MAX];
	char username[_SC_LOGIN_NAME_MAX];
	gethostname(hostname, _SC_HOST_NAME_MAX);
	getlogin_r(username, _SC_LOGIN_NAME_MAX);
	std::cout << "hostname: " << hostname << std::endl;
	std::cout << "username: " << username << std::endl;

	//version
	char str[256];
	size_t size = sizeof(str);
	// system("rm newinfo");
	int ret = sysctlbyname("kern.osproductversion", str, &size, NULL, 0);
	std::cout << "OS: ";
	if (str[4] == '3'){
		std::cout << "macOS High Siera" << std::endl;
	} else if (str[4] == '2'){
		std::cout << "macOS Siera" << std::endl;
	} else if (str[4] == '1'){
		std::cout << "OS X El Capitan" << std::endl;
	}
	std::cout << "version: " <<  str << std::endl;


	char strcpu[256];
	size = sizeof(strcpu);
	ret = sysctlbyname("machdep.cpu.brand_string", strcpu, &size, NULL, 0);
	std::cout << "CPU: " <<  strcpu << std::endl;
	int core_count;
	ret = sysctlbyname("machdep.cpu.core_count", &core_count, &size, NULL, 0);
	std::cout << "Cores: " << core_count << std::endl;
	system("top -l 1 | grep -E '^CPU' >> newinfo");
	std::ifstream cpu_usage ("newinfo");
	std::string line;
	getline(cpu_usage, line);
	std::cout << line << std::endl;
	cpu_usage.close();
	system("rm newinfo");
	system("top -l 1 | grep -E '^PhysMem:' >> newinfo");
	std::ifstream ram_usage ("newinfo");
	getline(ram_usage, line);
	std::cout << line << std::endl;
	ram_usage.close();
	system("rm newinfo");

	// uint64_t total = 0;
	// size_t size1 = sizeof(total);
	// uint32_t utotal = 0;
	// if( !sysctlbyname("hw.physmem", &total, &size1, NULL, 0) )
 //     	utotal = total;
 // std::cout << utotal << std::endl;

	// current date/time based on current system
   time_t now = time(0);


   tm *ltm = localtime(&now);

   // print various components of tm structure.
   std::cout << "Year: " << 1900 + ltm->tm_year<<std::endl;
   std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;
   std::cout << "Day: "<<  ltm->tm_mday << std::endl;
   std::cout << "Time: "<< 1 + ltm->tm_hour << ":";
   std::cout << 1 + ltm->tm_min << ":";
   std::cout << 1 + ltm->tm_sec << std::endl;
    CpuUsage a(0), b(1), c(2), d(3);
    sleep(1);
  std::cout << (a.get() +  b.get() + c.get() + d.get()) / 4 << std::endl;
  sleep(1);
  std::cout << (a.get() +  b.get() + c.get() + d.get()) / 4 << std::endl;
  sleep(1);
  std::cout << (a.get() +  b.get() + c.get() + d.get()) / 4<< std::endl;
  return 0;

}
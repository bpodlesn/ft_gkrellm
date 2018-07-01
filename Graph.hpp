/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:53:28 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 18:45:52 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

class Graph
{
	bool _visible;
	double _data;
	int _posX;
	int _posY;
	int _minX;
	double _oldX;
public:
	Graph(){};
	Graph(int x, int y, int mini);
	~Graph();
	bool getVisible();
	double getData();
	int getposX();
	int getposY();
	void setVisible(bool newVisible);
	void setData(double newdouble);
	void setposX(int X);
	void setposY(int Y);
	void setminX(int X);
	void setoldX(int X);
};

#endif
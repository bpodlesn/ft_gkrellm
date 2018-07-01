/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:55:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 18:47:32 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"

Graph::Graph(int x, int y, int mini){
	_visible = false;
	_data = 0;
	_oldX = x;
	_posX = x;
	_minX = mini;
	_posY = y;
}
Graph::~Graph(){};

bool Graph::getVisible(){
	return _visible;
};

double Graph::getData(){
	return _data;
};

int Graph::getposX(){
	return _posX;
};

int Graph::getposY(){
	return _posY;
}

void Graph::setVisible(bool newVisible){
	this->_visible = newVisible;
}
void Graph::setData(double newdouble){
	this->_data = newdouble;
}
void Graph::setposX(int X){
	if (this->_posX <= _minX){
		this->_visible = false;
		this->_posX = _oldX;
	}
	else
		this->_posX = X;
}
void Graph::setposY(int Y){
		this->_posY = Y;
}

void Graph::setminX(int X){
	this->_minX = X;
}

void Graph::setoldX(int X){
	this->_oldX = X;
}

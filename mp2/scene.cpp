#include "scene.h"
#include "image.h"
#include "png.h"
#include "rgbapixel.h"

#include <iostream>

using namespace std;

// constructor
Scene::Scene(int max){
	maxindex = max;
	myScene = new Image * [maxindex];
	xcoord = new int [maxindex];
	ycoord = new int [maxindex];
	for (int i = 0; i < maxindex; i++) {
		myScene[i] = NULL;
		xcoord[i] = 0;
		ycoord[i] = 0;
	}
}

// destructor
Scene::~Scene(){
	clear();
}

// copy constructor
Scene::Scene(const Scene & source){
	if (this != &source){
		copy(source);
	}
}

const Scene & Scene::operator=(const Scene & source){
	if (this != &source){
		clear();
		copy(source);
	}
	return *this;
}

void Scene::changemaxlayers(int newmax){
	if (maxindex == newmax){
		return;
	}
	if (maxindex > newmax){
		for (int i = newmax-1; i < maxindex; i++) {
			if (myScene[i] != NULL) {
				cout << "invalid newmax" << endl;
				return;
			}
		}
	}
	maxindex = newmax;
	Image ** tempScene;
	int * tempxcoord;
	int * tempycoord;
	tempScene = new Image * [maxindex];
	tempxcoord = new int [maxindex];
	tempycoord = new int [maxindex];
	for (int i = 0; i < maxindex; i++) {
		if(myScene[i] != NULL){
			tempScene[i] = myScene[i];
		}
		tempxcoord[i] = xcoord[i];
		tempycoord[i] = ycoord[i];
	}
	clear();
	myScene = tempScene;
	xcoord = tempxcoord;
	ycoord = tempycoord;
}

void Scene::addpicture(const char* FileName, int index, int x, int y){
	if ((index >= maxindex) || (index < 0)){
		cout << "index out of bounds" << endl;
	}
	Image * newImage = new Image();
	newImage->readFromFile(FileName);
	if (myScene[index] != NULL){
		delete myScene[index];
		myScene[index] = NULL;
	}
	myScene[index] = newImage;
	xcoord[index] = x;
	ycoord[index] = y;
}

void Scene::changelayer(int index, int newindex){
	if (index == newindex){
		return;
	}
	if ((newindex >= maxindex) || (index >= maxindex) || (index < 0) || (newindex < 0)){
		cout << "invalid index" << endl;
		return;
	}
	if (myScene[newindex] != NULL){
		delete myScene[newindex];
		myScene[newindex] = NULL;
	}
	myScene[newindex] = myScene[index];
	xcoord[newindex] = xcoord[index];
	ycoord[newindex] = ycoord[index];
	myScene[index] = NULL;
}

void Scene::translate(int index, int xcoord, int ycoord){
	if ((index >= maxindex) || (index < 0) || (myScene[index] == NULL)){
		cout << "invalid index" << endl;
		return;
	}
	this->xcoord[index] = xcoord;
	this->ycoord[index] = ycoord;
}

void Scene::deletepicture(int index){
	if ((index >= maxindex) || (index < 0) || (myScene[index] == NULL)){
		cout << "invalid index" << endl;
		return;
	}
	delete myScene[index];
	myScene[index] = NULL;
}

Image * Scene::getpicture(int index) const{
	if ((index >= maxindex) || (index < 0) || (myScene[index] == NULL)){
		cout << "invalid index" << endl;
		return NULL;
	}
	return myScene[index];
}

Image Scene::drawscene()const{
	size_t sceneHeight = 0;
	size_t sceneWidth = 0;
	for (int i = 0; i < maxindex; i++) {
		if (myScene[i] != NULL){
			if (sceneHeight < (myScene[i]->height() + ycoord[i])){
				sceneHeight = (myScene[i]->height() + ycoord[i]);
			}
			if (sceneWidth < (myScene[i]->width() + xcoord[i])){
				sceneWidth = (myScene[i]->width() + xcoord[i]);
			}
		}
	}
	Image newScene(sceneWidth, sceneHeight);
	RGBAPixel * newPixel;
	for (int i = 0; i < maxindex; i++){
		if (myScene[i] != NULL){
			for (size_t j = 0; j < myScene[i]->width(); j++){
				for (size_t k = 0; k < myScene[i]->height(); k++){
					newPixel = newScene(xcoord[i] + j,ycoord[i] + k);
					*newPixel = *(*myScene[i])(j,k);
				}
			}
		}
	}
	return newScene;
}

// help function : copy
void Scene::copy(const Scene &source){
	maxindex = source.maxindex;
	myScene = new Image*[maxindex];
	xcoord = new int [maxindex];
	ycoord = new int [maxindex];
	for (int i = 0; i < maxindex; i++){
		myScene[i] = NULL;
		xcoord[i] = 0;
		ycoord[i] = 0;
		if (source.myScene[i] != NULL){
			myScene[i] = new Image;
			*myScene[i] = *(source.myScene[i]);
			xcoord[i] = source.xcoord[i];
			ycoord[i] = source.ycoord[i];
		}
	}
}

// help function : clear
void Scene::clear(){
	for (int i = 0; i < maxindex; i++) {
			delete myScene[i];
			myScene[i] = NULL;
	}
	delete [] myScene;
	myScene = NULL;
	delete [] xcoord;
	xcoord = NULL;
	delete [] ycoord;
	ycoord = NULL;
}

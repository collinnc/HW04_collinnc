#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "CollinncStarbucks.h"
#include <iostream>
#include <fstream>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_collinncApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	Entry* makeArray();
	int num_items;
};

void HW04_collinncApp::setup()
{
	num_items=0;
	//ifstream in("x.txt");
	ifstream in("Starbucks_2006.csv");
	//string line;
	//getline(in,line,',');
	//in.close();
	//app::console()<<line<<endl;
	//in.close();
	Entry* entries = makeArray();
	for(int i=0; i<10;i++){
		app::console()<<(entries+i)->identifier<<endl;
	}
}

Entry* HW04_collinncApp::makeArray(){
	
	ifstream in("Starbucks_2006.csv");
	string line;
	//find num_items
	while(in.good()){
		getline(in, line, '\r');
		num_items++;
	}	
	// Go back to beginning of input
	in.clear();
	in.seekg(0);

	double xPos, yPos;
	int i=0;
	Entry* arr = new Entry[num_items];
	while(in.good()){
	//for(int i = 0; i<num_items; i++){
		getline(in,line,',');
		in>>xPos;
		in.get();
		in>>yPos;
		(arr+i) -> identifier = line;
		(arr+i)->x = xPos;
		(arr+i)->y = yPos;
		i++;
	}
	in.close();
	return arr;
}

void HW04_collinncApp::mouseDown( MouseEvent event )
{
}

void HW04_collinncApp::update()
{
}

void HW04_collinncApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04_collinncApp, RendererGl )

#include "ofApp.h"
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

//--------------------------------------------------------------
void ofApp::setup(){
    std::string str;
    int ival;
    double dval;
    
    // 番号で指定された通りに値を文字列化
    str = (boost::format("%1% %2% %3%") % 1 % "abc" % 3.14).str();
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // printf のフォーマット文も利用可能
    str = (boost::format("%06X (hex)") % 12648430).str();
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    str = (boost::format("%d (dec)") % 0xDEADBEEF).str();
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // lexical_cast を利用した整数から文字列への変換
    str = boost::lexical_cast<std::string>(141421356);
    std::cout << str << " (string)" << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // lexical_cast を利用した文字列から整数への変換
    ival = boost::lexical_cast<int>(str);
    std::cout << ival << " (int)" << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // lexical_cast を利用した文字列から実数への変換
    str = "0.12345";
    dval = boost::lexical_cast<double>(str);
    std::cout << dval << " (double)" << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // lexical_cast を利用した不正な文字列から実数への変換
    str = "0.12???";
    try {
        dval = boost::lexical_cast<double>(str);
    }
    catch (boost::bad_lexical_cast& e) {
        dval = NAN;
    }
    std::cout << dval << " (double)" << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
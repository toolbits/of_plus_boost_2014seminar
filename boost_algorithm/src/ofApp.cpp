#include "ofApp.h"
#include <boost/algorithm/string.hpp>

//--------------------------------------------------------------
void ofApp::setup(){
    // Boost String Algorithms Library
    // -> http://www.boost.org/doc/libs/1_56_0/doc/html/string_algo.html
    
    std::string str;
    std::vector<std::string> vec;
    std::vector<std::string>::iterator it;
    
    // 元の文字列
    str = " Hello boost ";
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 両端の空白を削除
    boost::algorithm::trim(str);
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // カンマ区切りのいくつかの要素
    str = "H, He,  Li  ,Be,  B , C, N  ,  O,    F , Ne";
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // カンマで文字列を分割
    boost::algorithm::split(vec, str, boost::is_any_of(","));
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 分割した各文字列の両端の空白を削除
    for (it = vec.begin(); it != vec.end(); ++it) {
        boost::algorithm::trim(*it);
    }
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 各文字列を｜を区切りにして連結
    str = boost::algorithm::join(vec, "|");
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 文字列の置き換え
    boost::algorithm::replace_all(str, "|", " / ");
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 文字列を置き換えた結果を返す
    str = boost::algorithm::replace_first_copy(std::string("C++ source code"), "C++", "boooooooooooooooost");
    std::cout << str << std::endl;
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
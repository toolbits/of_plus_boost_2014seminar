#include "ofApp.h"
#include <boost/regex.hpp>

//--------------------------------------------------------------
void ofApp::setup(){
    std::string str;
    boost::regex regex("[^/]+?\\.o$");
    std::string::const_iterator bit;
    std::string::const_iterator eit;
    boost::match_results<std::string::const_iterator> result;
    
    // 正規検索を適応する文字列
    str = ""
        "clang-darwin.compile.c++ bin.v2/libs/math/build/clang-darwin-4.2.1/release/address-model-32_64"
        "/architecture-x86/link-static/pch-off/threading-multi/cyl_bessel_i.o"
        "\nclang-darwin.compile.c++ bin.v2/libs/math/build/clang-darwin-4.2.1/release/address-model-32_64"
        "/architecture-x86/link-static/pch-off/threading-multi/cyl_bessel_j.o"
        "\nclang-darwin.compile.c++ bin.v2/libs/math/build/clang-darwin-4.2.1/release/address-model-32_64"
        "/architecture-x86/link-static/pch-off/threading-multi/cyl_bessel_k.o"
        "\nclang-darwin.compile.c++ bin.v2/libs/math/build/clang-darwin-4.2.1/release/address-model-32_64"
        "/architecture-x86/link-static/pch-off/threading-multi/cyl_neumann.o"
    "";
    std::cout << str << std::endl;
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 見つかった項目をすべて表示
    bit = str.begin();
    eit = str.end();
    while (boost::regex_search(bit, eit, result, regex)) {
        std::cout << "match = " << result.str() << std::endl;
        bit = result[0].second;
    }
    std::cout << "---- ---- ---- ----" << std::endl;
    
    // 見つかった項目をすべて置換
    str = boost::regex_replace(str, regex, "********.o");
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
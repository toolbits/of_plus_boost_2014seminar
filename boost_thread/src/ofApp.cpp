#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(void)
{
    // 新しいスレッドを作成して実行
    try {
        _thread = boost::thread(boost::bind(&ofApp::thread, this));
    }
    catch (std::exception& e) {
        std::cout << "an exception occurred : " << e.what() << std::endl;
    }
    return;
}

void ofApp::exit(void)
{
    // スレッドを中断し、終了するまで待機
    _thread.interrupt();
    try {
        _thread.join();
    }
    catch (...) {
    }
    return;
}

void ofApp::thread(void)
{
    int count;
    
    std::cout << "thread start" << std::endl;
    count = 0;
    while (!boost::this_thread::interruption_requested()) {
        
        // カウント値を表示
        std::cout << count++ << std::endl;
        
        // スレッドを１秒間スリープ
        // スリープ中に外部スレッドから中断されたらループを抜ける
        try {
            boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        }
        catch (boost::thread_interrupted& e) {
            break;
        }
    }
    std::cout << "thread stop" << std::endl;
    return;
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
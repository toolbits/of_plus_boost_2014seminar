#include "ofApp.h"
#include <boost/format.hpp>

//--------------------------------------------------------------
void ofApp::setup(void)
{
    // 変数を初期化
    _count = 0;
    
    // 新しいスレッドを作成して実行
    try {
        _thread = boost::thread(boost::bind(&ofApp::thread, this));
    }
    catch (std::exception& e) {
        std::cout << "an exception occurred : " << e.what() << std::endl;
    }
    
    ofBackground(0, 0, 0);
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
    std::cout << "thread start" << std::endl;
    while (!boost::this_thread::interruption_requested()) {
        
        // カウント変数を増加
        _mutex.lock();
        ++_count;
        _mutex.unlock();
        
        // スレッドを３３ミリ秒間スリープ
        // スリープ中に外部スレッドから中断されたらループを抜ける
        try {
            boost::this_thread::sleep(boost::posix_time::milliseconds(33));
        }
        catch (boost::thread_interrupted& e) {
            break;
        }
    }
    std::cout << "thread stop" << std::endl;
    return;
}

//--------------------------------------------------------------
void ofApp::update(void)
{
    // lock() / unlock() の替わりに lock_guard を利用しても同じ
    boost::lock_guard<boost::mutex> guard(_mutex);
    
    // カウント変数を減少
    --_count;
    return;
}

//--------------------------------------------------------------
void ofApp::draw(void)
{
    int count;
    ofColor color;
    
    // カウント値を取得
    _mutex.lock();
    count = _count;
    _mutex.unlock();
    
    // カウント値を表示
    color.setHsb(abs(count) % 255, 255, 255);
    ofBackground(color);
    ofDrawBitmapString((boost::format("%1%") % count).str(), 10, 50);
    return;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    // スペースキーを押すとメインスレッドを３秒間停止
    switch (key) {
        case ' ':
            sleep(3);
            break;
    }
    return;
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
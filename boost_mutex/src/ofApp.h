#pragma once

#include "ofMain.h"
#include <boost/thread.hpp>

class ofApp : public ofBaseApp{
    private:
        // boost を利用したスレッド
        boost::thread _thread;
    
        // ２つのスレッドから参照される変数
        int _count;
    
        // 変数へのアクセスを排他にするための mutex
        boost::mutex _mutex;
    
	public:
		void setup();
        void exit();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    private:
        // 新しいスレッドで実行される関数
        void thread(void);
};

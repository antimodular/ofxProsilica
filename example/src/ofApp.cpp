#include "ofApp.h"

//make sure to copr libPvAPI.dylib in to app/Contents/MacOS
//--------------------------------------------------------------
void ofApp::setup(){
    
    //	ofSetVerticalSync(false);
    
    ofBackground(100, 50, 50);
    ofSetLogLevel(OF_LOG_VERBOSE);
//    cameraA.listDevices();
//    ofSetLogLevel(OF_LOG_NOTICE);
    
    //if you think the camera is set to an IP 169.254.x.x then set the computer to DHCP
    //otherwise set the computer to the same IP range
    // pre setup features
    cameraA.setDeviceID(6001472); //126659); //6002018); //115230); // for the interface to work correctly set the deviceID
    //mako on ceiling 6001010
    //tym mako 6002281
    //ge1910 115230 marked with ip 169.254.28.66
    //ge1910 115234 SN:02-2083C-06190
    //ge1910 117771 SN:
    //gc0650c 33339, 100249, 126659 (red in back)
    //126659 169.254.28.186
    //GC650M 32550  IP:192.168.0.100 (set computer to similar IP)
    //	cameraA.setPersistentIpAdress(10.0.0.66);
    //	cameraA.setPersistentIpSubnetMask(255.0.0.0);
    //	cameraA.setPersistentIp(true);
    cameraA.setPixelFormat(OF_PIXELS_RGB);
    cameraA.setup();
    
    
    while(cameraA.isInitialized() == false){
        cameraA.update();
        //  cout<<"camWidth "<<camWidth<<" , "<<camHeight<<endl;
    }
    
  
    
    gui_main.setup("settings");
    gui_main.add(fps.set("FPS", 0, 0, 100));
    gui_main.setPosition(ofGetWidth()-300, 10);
    gui_main.add(bShowGui.set("Show Gui (tilde)", true));
    gui_main.add(cameraA.parameters);
    gui_main.loadFromFile("gui_main.xml");
    
    img.allocate(cameraA.getWidth(), cameraA.getHeight(), OF_IMAGE_COLOR);

    
    ofLog()<<cameraA.getWidth()<<" x "<<cameraA.getHeight();
    int glFormat = ofGetGLInternalFormatFromPixelFormat(cameraA.getPixelFormat());
    ofLog()<<"glFormat "<<glFormat;
}

//--------------------------------------------------------------
void ofApp::update(){
    cameraA.update();
    fps.set(ofGetFrameRate() + 0.5);
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofClear(0);

    if (cameraA.isFrameNew()){
//        ofLog()<<"cameraA.isFrameNew()";
           cameraTimer.tick();
         int w = cameraA.getWidth();
         int h = cameraA.getHeight();
//        int glFormat = ofGetGLInternalFormatFromPixelFormat(cameraA.getPixelFormat());
        //        ofLog()<<"glFormat "<<glFormat;
        if (tex.getWidth() != w || tex.getHeight() != h){ // || tex.getTextureData().glTypeInternal != glFormat) {
//            tex.clear();
//            tex.allocate(w, h, glFormat);
        }
        
        //		tex.loadData(cameraA.getPixels(), w, h, glFormat);
//        ofPixels pix = cameraA.getPixels();
//        tex.loadData(cameraA.getPixels()); //,w,h,tex.getTextureData().glInternalFormat);
//        tex.loadData(pix);
//        int t = 0;
//        for(int i=0; i< 100; i++){
//            int r = ofRandom(1200);
//            ofLog()<<cameraA.getPixels().getColor(r);
////            if(t > 300) break;
//        }
//        ofLog()<<"cameraA.getPixels() "<<cameraA.getPixels().getWidth();
        img.setFromPixels(cameraA.getPixels());
       }
    
    
//    tex.draw(0,0,ofGetWidth(),ofGetHeight()); //,1920/2,1080/2);
    
    ofSetColor(255);
    img.draw(10,10,604,480);
    
    if (bShowGui.get())
        gui_main.draw();
    
    ofDrawBitmapStringHighlight("cam fps    "+ofToString(cameraTimer.getFramerate(),0),100,30);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            //			cameraA.close();
            break;
        case 'g':
            bShowGui = !bShowGui;
            if(bShowGui == false){
                gui_main.saveToFile("gui_main.xml");   
            }
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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

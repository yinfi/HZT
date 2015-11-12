#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("LessonMenuScene.csb");

    addChild(rootNode);

	ActionTimeline * actionCloud = CSLoader::createTimeline("CloudNode.csb");
	rootNode->runAction(actionCloud);
	actionCloud->gotoFrameAndPlay(0, 260, true);

	ActionTimeline * actionRedBallon = CSLoader::createTimeline("BallonRedNode.csb");
	rootNode->runAction(actionRedBallon);
	actionRedBallon->gotoFrameAndPlay(0, 135, true);

	ActionTimeline * actionBlueBallon = CSLoader::createTimeline("BallonBlueNode.csb");
	rootNode->runAction(actionBlueBallon);
	actionBlueBallon->gotoFrameAndPlay(0, 140, true);

	ActionTimeline * actionCloud2 = CSLoader::createTimeline("Cloud2Node.csb");
	rootNode->runAction(actionCloud2);
	actionCloud2->gotoFrameAndPlay(0, 280, true);


	//cloud = dynamic_cast<Sprite*>(seekNodeByName(rootNode, std::string("ProjectNode_1")));
	//cloud = dynamic_cast<Sprite*>(CSLoader::createNode("Cloud2Node.csb"));
	//auto tl = CSLoader::createTimeline("Cloud2Node.csb");
	//cloud->setAnchorPoint(Vec2(0.5,0.5));
	//auto cloudMove = CSLoader::createTimeline("Cloud2Node.csb");
	//cloud->runAction(cloudMove);
	//cloudMove->play("cloud2_1",true);
	//cloud->runAction(tl);
	//tl->gotoFrameAndPlay(0, true);

	return true;

}
/*Node* HelloWorld::seekNodeByName(cocos2d::Node* root, std::string& name){
	if (!root){
		return nullptr;
	}
	if (root->getName() == name){
		return root;
	}
	const auto& arryNode = root->getChildren();
	for (auto& node : arryNode){
		Node* child = dynamic_cast<Node*>(node);
		if (child){
			Node* res = seekNodeByName(child, name);
		}
	}
£ý*/
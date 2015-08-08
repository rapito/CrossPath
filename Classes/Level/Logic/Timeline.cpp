#include "Timeline.h"

Timeline * Timeline::_instance;
Timeline * Timeline::getInstance()
{
	return !_instance ? (_instance= new Timeline()):_instance;
}

void Timeline::update(Track* track)
{

}
void drawTimeLine(Track * track, CCSize * size)
{
	ccColor4F baseColor=ccc4f(0.117f,0.0f,0.038f,0.6f/*9*/);
	ccDrawSolidRect(CCPoint(0,track->getContentSize().height),CCPoint(size->width,track->getContentSize().height+size->height),baseColor);
	float recThickness=4.0f;
	glLineWidth(recThickness);
	ccDrawColor4F(baseColor.r,baseColor.g,baseColor.b,0.9);
	ccDrawRect(ccp(0-recThickness,track->getContentSize().height-recThickness/2),ccp(size->width+recThickness/2 , track->getContentSize().height+size->height+recThickness/2));
}
void drawTBars(Track *track,CCPoint * timelineTrackRatio,CCSize * timeLineSize,float * addtionalDistance)
{
	float porcentMaxSize=0.2f;
	float maxSize=track->_entBar[0]->getWidth()*porcentMaxSize;
	float sizeReductor=0.0f;
	float barsWidth=track->_entBar[0]->getWidth()*timelineTrackRatio->x;
	//if(barsWidth>=maxSize)
		//sizeReductor=track->_entBar[0]->getWidth()- track->_entBar[0]->getWidth()*porcentMaxSize;
		sizeReductor=track->_entBar[0]->getWidth()*porcentMaxSize;
	ccColor4F color;
	
	float trackHeight=track->getHeight();
	float newX,newY;
	for (int i=0;i<track->_entBar.size();i++)
	{
		if(track->_entBar[i]->getClassName()=="Bar")
			color=ccc4f(0.0f,1.0f,0.0f,0.80f);
		else if(track->_entBar[i]->getClassName()=="StartBar" || track->_entBar[i]->getClassName()=="EndBar")
			color=ccc4f(1.0f,1.0f,0.0f,0.80f);
		else
			color=ccc4f(0,0.392f,1.0f,0.80f);
		newX=(track->_entBar[i]->getPositionX()+*addtionalDistance)*timelineTrackRatio->x ;
		newY=track->_entBar[i]->getHeight()*timelineTrackRatio->y;
		/*ccDrawSolidRect(ccp(newX + sizeReductor/2,newY + trackHeight),ccp(newX + barsWidth -sizeReductor/2,trackHeight),color);*/
		ccDrawSolidRect(ccp(newX + barsWidth/2 -sizeReductor/2,newY + trackHeight),ccp(newX  + barsWidth/2 + sizeReductor/2,trackHeight),color);
	}
}
void drawTItems(Track *track,CCPoint * timelineTrackRatio,CCSize * timeLineSize,float * addtionalDistance)
{
	
	float trackHeight=track->getHeight();
	float itemThickness=10.f;
	glLineWidth(itemThickness);
	float radius=timeLineSize->height/6;
	float newX,newY;
	for (int i=0;i < track->_items.size();i++)
	{
		if(track->_items[i]->getClassName()=="StarItem" &&  track->_items[i]->isVisible())
		{
			newX=(track->_items[i]->getPositionX()  + *addtionalDistance)* timelineTrackRatio->x;
			newY=timeLineSize->height/2 + trackHeight;
		//	ccDrawCircle(track->_items[i]->getPosition(),10,CC_DEGREES_TO_RADIANS(90),180,false,1.5f,1.5f);
			ccDrawColor4F(0.5f,0.1f,0.0f,0.1f);
			ccDrawCircle(ccp(newX,newY),radius,CC_DEGREES_TO_RADIANS(90),180,false,1.5f,1.5f);
		}
	}
}
void drawTPlayer(Track * track,CCPoint * timelineTrackRatio,CCSize * timeLineSize,float * addtionalDistance)
{
	float trackHeight=track->getHeight();
	float radius=timeLineSize->height/5;
	ccDrawColor4F(0.75f,0.0f,0.0f,0.8f);
	float newX=(track->_player->getPositionX() + *addtionalDistance)* timelineTrackRatio->x;
	float newY=timeLineSize->height/2 + trackHeight;
	
	ccDrawSolidCircle(ccp(newX,newY),radius,CC_DEGREES_TO_RADIANS(90),50,false);
}
float getSpaceBetweenBars(int  barsQuantity, float  barsSize, float  screenSize)
{
	return (screenSize-(barsQuantity*barsSize))/(barsQuantity+1);
}
float getBarsMargin()
{
	return CCDirector::sharedDirector()->getWinSize().width/CommonKeys::_CONST_MAX_BAR_PER_SCREEN; 
}
float getDistanceFrom(Track * track)
{
	return std::abs(track->_entBar[0]->getPositionX() -getBarsMargin()/2); 
}
CCPoint getTimelineTrackRatio(Track * track, CCSize * timeLineSize)
{
	float trackFullWidth;
	float barsQuantity=track->_entBar.size();
	float barsMargin;
	float barsWidth=track->_entBar[0]->getWidth();
	CCPoint ratio;

	barsMargin=getBarsMargin();//CCDirector::sharedDirector()->getWinSize().width/CommonKeys::_CONST_MAX_BAR_PER_SCREEN; 

	trackFullWidth=barsMargin*barsQuantity;//barsQuantity*barsWidth + (barsMargin/2 + (barsQuantity-1)*barsMargin); 

	ratio.x=timeLineSize->width/trackFullWidth;

	ratio.y=timeLineSize->height/track->getHeight();
	return ratio;
}
void Timeline::render(Track* track)
{
	CCSize * timeLineSize=new CCSize(CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height/20);
	CCPoint *timelineTrackRatio=new CCPoint(getTimelineTrackRatio(track,timeLineSize));
	float * addtionalDistance=new float(getDistanceFrom(track));
	drawTimeLine(track,timeLineSize);
	drawTBars(track,timelineTrackRatio,timeLineSize,addtionalDistance);
	drawTItems(track,timelineTrackRatio,timeLineSize,addtionalDistance);
	drawTPlayer(track,timelineTrackRatio,timeLineSize,addtionalDistance);
	ccDrawColor4F(0xFF,0xFF,0xFF,0xFF);
	glLineWidth(1.0f);
}

Timeline::Timeline(void)
{

}



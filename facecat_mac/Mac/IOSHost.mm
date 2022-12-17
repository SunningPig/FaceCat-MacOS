/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#include "stdafx.h"
#include "IOSHost.h"
#include "RibbonButton.h"
#include "UIXmlEx.h"
#include "MainFrame.h"
#include "DataCenter.h"
#import "ViewController.h"

IOSTimer::IOSTimer(){
    m_interval = 1000;
    m_tick = 0;
    m_timerID = 0;
}

IOSTimer::~IOSTimer(){
    
}

ScrollButtonM::ScrollButtonM(){
    m_arrowType = 0;
}

ScrollButtonM::~ScrollButtonM(){
    
}

void ScrollButtonM::onPaint(FCPaint *paint, const FCRect& clipRect){
    int width = getWidth(), height = getHeight();
    FCRect drawRect = {0, 0, width, height};
    if(m_arrowType == 5){
        if(MyColor::getStyle() == 1){
            if(this == m_native->getHoveredView()){
                paint->fillRoundRect(USERCOLOR5, drawRect, 4);
            }else{
                paint->fillRoundRect(USERCOLOR16, drawRect, 4);
            }
        }else{
            if(this == m_native->getHoveredView()){
                paint->fillRoundRect(USERCOLOR5, drawRect, 4);
            }else{
                paint->fillRoundRect(USERCOLOR74, drawRect, 4);
            }
        }
    }else if(m_arrowType == 6){
        if(this == m_native->getHoveredView()){
            paint->fillRect(USERCOLOR6, drawRect);
        }
    }
    else{
        if(allowDrag() && this == m_native->getHoveredView()){
            paint->fillRect(USERCOLOR5, drawRect);
        }else{
            if(MyColor::getStyle() == 0 || MyColor::getStyle() == 1 || MyColor::getStyle() == 6){
                paint->fillRect(FCColor_Border, drawRect);
            }else{
                paint->fillRect(USERCOLOR74, drawRect);
            }
        }
    }
    if(this == m_native->getHoveredView()){
        int mw = width / 2, mh = height / 2;
        FCPoint point1 = {0};
        FCPoint point2 = {0};
        FCPoint point3 = {0};
        int ts = 3;
        switch (m_arrowType){
            case 1:
                point1.x = mw - ts;
                point1.y = mh;
                point2.x = mw + ts;
                point2.y = mh - ts * 3;
                point3.x = mw + ts;
                point3.y = mh + ts * 3;
                break;
            case 2:
                point1.x = mw + ts;
                point1.y = mh;
                point2.x = mw - ts;
                point2.y = mh - ts * 3;
                point3.x = mw - ts;
                point3.y = mh + ts * 3;
                break;
            case 3:
                point1.x = mw;
                point1.y = mh - ts;
                point2.x = mw - ts * 3;
                point2.y = mh + ts;
                point3.x = mw + ts * 3;
                point3.y = mh + ts;
                break;
            case 4:
                point1.x = mw;
                point1.y = mh + ts;
                point2.x = mw - ts * 3;
                point2.y = mh - ts;
                point3.x = mw + ts * 3;
                point3.y = mh - ts;
                break;
        }
        FCPoint points[3];
        points[0] = point1;
        points[1] = point2;
        points[2] = point3;
        paint->fillPolygon(USERCOLOR, points, 3);
    }
}

void ScrollButtonM::onPaintBorder(FCPaint *paint, const FCRect& clipRect){
    
}

static int m_staticID = 0;

IOSHost::IOSHost(){
    m_allowOperate = true;
    m_allowPartialPaint = true;
    m_isViewAppear = true;
    m_mousePoint.x = 0;
    m_mousePoint.y = 0;
    m_native = 0;
    m_view = 0;
    m_staticID++;
    m_id = m_staticID;
}

IOSHost::~IOSHost(){
    m_native = 0;
    map<int, IOSTimer*>::iterator sIter = m_timers.begin();
    for(; sIter != m_timers.end(); ++sIter){
        delete sIter->second;
    }
    m_timers.clear();
    m_view = 0;
}

FCNative* IOSHost::getNative(){
    return m_native;
}

void IOSHost::setNative(FCNative *native)
{
    m_native = native;
}

NSView* IOSHost::getView(){
    return m_view;
}

void IOSHost::setView(NSView *view){
    m_view = view;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CGPoint IOSHost::getCGPoint(const FCPoint& point){
    return CGPointMake(point.x, point.y);
}

CGRect IOSHost::getCGRect(const FCRect& rect){
    int rw = rect.right - rect.left;
    int rh = rect.bottom - rect.top;
    if(rw < 0){
        rw = 0;
    }
    if(rh < 0){
        rh = 0;
    }
    return CGRectMake(rect.left, rect.top, rw, rh);
}

CGSize IOSHost::getCGSize(const FCSize& size){
    return CGSizeMake(size.cx, size.cy);
}

NSString* IOSHost::getNSString(const wchar_t *str){
    string fstr = FCTran::StringTostring(str);
    return [NSString stringWithUTF8String:fstr.c_str()];
}

FCPoint IOSHost::getPoint(CGPoint cgPoint){
    FCPoint point = {(int)cgPoint.x, (int)cgPoint.y};
    return point;
}

FCRect IOSHost::getRect(CGRect cgRect){
    FCRect rect = {(int)cgRect.origin.x, (int)cgRect.origin.y, (int)(cgRect.origin.x + cgRect.size.width),
        (int)(cgRect.origin.x + cgRect.size.height)};
    return rect;
}

FCSize IOSHost::getSize(CGSize cgSize){
    FCSize size = {(int)cgSize.width, (int)cgSize.height};
    return size;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IOSHost::allowOperate(){
    return m_allowOperate;
}

bool IOSHost::allowPartialPaint(){
    return m_allowPartialPaint;
}

void IOSHost::beginInvoke(FCView *view, void *args){
    if([NSThread isMainThread] == YES){
        view->onInvoke(args);
    }else{
        dispatch_sync(dispatch_get_main_queue(), ^{
            view->onInvoke(args);
        });
    }
}

void IOSHost::copy(string text){
    NSPasteboard *paste = [NSPasteboard generalPasteboard];
    if(paste){
        [paste clearContents];
        NSString *nsStr = [NSString stringWithUTF8String:text.c_str()];
        [paste writeObjects:@[nsStr]];
    }
}

FCView* IOSHost::createInternalView(FCView *parent, const String& clsid){
    FCCalendar *calendar = dynamic_cast<FCCalendar*>(parent);
    if (calendar)
    {
        if (clsid == L"datetitle"){
            return new DateTitle(calendar);
        }
        else if (clsid == L"headdiv"){
            HeadDiv *headDiv = new HeadDiv(calendar);
            headDiv->setWidth(parent->getWidth());
            headDiv->setDock(FCDockStyle_Top);
            return headDiv;
        }
        else if (clsid == L"lastbutton"){
            return new ArrowButton(calendar);
        }
        else if (clsid == L"nextbutton"){
            ArrowButton *nextBtn = new ArrowButton(calendar);
            nextBtn->setToLast(false);
            return nextBtn;
        }
    }
    FCSplitLayoutDiv *splitLayoutDiv = dynamic_cast<FCSplitLayoutDiv*>(parent);
    if (splitLayoutDiv){
        if (clsid == L"splitter"){
            ScrollButtonM *splitter = new ScrollButtonM;
            splitter->setBackColor(FCColor_Border);
            splitter->setBorderColor(FCColor_Border);
            FCSize size = {5, 5};
            splitter->setSize(size);
            return splitter;
        }
    }
    FCScrollBar *scrollBar = dynamic_cast<FCScrollBar*>(parent);
    if (scrollBar){
        FCSize sSize = {8, 8};
        scrollBar->setSize(sSize);
        scrollBar->setBorderColor(FCColor_None);
        scrollBar->setBackColor(FCColor_None);
        if (clsid == L"addbutton"){
            RibbonButton *addButton = new RibbonButton;
            FCSize size = {0, 0};
            addButton->setSize(size);
            if (dynamic_cast<FCScrollBar*>(scrollBar)){
                addButton->setArrowType(2);
            }
            else{
                addButton->setArrowType(4);
            }
            return addButton;
        }
        else if (clsid == L"backbutton"){
            ScrollButtonM *backButton = new ScrollButtonM;
            backButton->setBackColor(FCColor_None);
            backButton->setBorderColor(FCColor_None);
            backButton->m_arrowType = 6;
            return backButton;
        }
        else if (clsid == L"scrollbutton"){
            ScrollButtonM *scrollButton = new ScrollButtonM;
            scrollButton->setAllowDrag(true);
            scrollButton->setBackColor(USERCOLOR74);
            scrollButton->setBorderColor(FCColor_None);
            scrollButton->setCornerRadius(4);
            scrollButton->m_arrowType = 5;
            return scrollButton;
        }
        else if (clsid == L"reducebutton"){
            RibbonButton *reduceButton = new RibbonButton;
            FCSize size = {0, 0};
            reduceButton->setSize(size);
            if (dynamic_cast<FCHScrollBar*>(scrollBar)){
                reduceButton->setArrowType(1);
            }
            else{
                reduceButton->setArrowType(3);
            }
            return reduceButton;
        }
    }
    FCTabPage *tabPage = dynamic_cast<FCTabPage*>(parent);
    if (tabPage){
        if (clsid == L"headerbutton"){
            RibbonButton *button = new RibbonButton;
            button->setAllowDrag(true);
            FCSize size = {100, 20};
            button->setSize(size);
            return button;
        }
    }
    FCComboBox *comboBox = dynamic_cast<FCComboBox*>(parent);
    if (comboBox){
        if (clsid == L"dropdownbutton"){
            RibbonButton *dropDownButton = new RibbonButton;
            dropDownButton->setArrowType(4);
            dropDownButton->setDisplayOffset(false);
            int width = comboBox->getWidth();
            int height = comboBox->getHeight();
            FCPoint location = {width - 20, 0};
            dropDownButton->setLocation(location);
            FCSize size = {20, height};
            dropDownButton->setSize(size);
            return dropDownButton;
        }
        else if (clsid == L"dropdownmenu"){
            FCComboBoxMenu *comboBoxMenu = new FCComboBoxMenu;
            comboBoxMenu->setComboBox(comboBox);
            comboBoxMenu->setPopup(true);
            FCSize size = {100, 200};
            comboBoxMenu->setSize(size);
            return comboBoxMenu;
        }
    }
    FCDateTimePicker *datePicker = dynamic_cast<FCDateTimePicker*>(parent);
    if (datePicker){
        if (clsid == L"dropdownbutton"){
            RibbonButton *dropDownButton = new RibbonButton;
            dropDownButton->setArrowType(4);
            dropDownButton->setDisplayOffset(false);
            int width = datePicker->getWidth();
            int height = datePicker->getHeight();
            FCPoint location = {width - 16, 0};
            dropDownButton->setLocation(location);
            FCSize size = {16, height};
            dropDownButton->setSize(size);
            return dropDownButton;
        }
        else if (clsid == L"dropdownmenu"){
            FCMenu *dropDownMenu = new FCMenu();
            FCPadding padding(1);
            dropDownMenu->setPadding(padding);
            dropDownMenu->setPopup(true);
            FCSize size = {200, 200};
            dropDownMenu->setSize(size);
            return dropDownMenu;
        }
    }
    FCSpin *spin = dynamic_cast<FCSpin*>(parent);
    if (spin){
        if (clsid == L"downbutton"){
            RibbonButton *downButton = new RibbonButton;
            downButton->setArrowType(4);
            downButton->setDisplayOffset(false);
            FCSize size = {16, 16};
            downButton->setSize(size);
            return downButton;
        }
        else if (clsid == L"upbutton"){
            RibbonButton *upButton = new RibbonButton;
            upButton->setArrowType(3);
            upButton->setDisplayOffset(false);
            FCSize size = {16, 16};
            upButton->setSize(size);
            return upButton;
        }
    }
    FCDiv *div = dynamic_cast<FCDiv*>(parent);
    if (div){
        if (clsid == L"hscrollbar"){
            FCHScrollBar *hScrollBar = new FCHScrollBar;
            hScrollBar->setVisible(false);
            FCSize size = {10, 10};
            hScrollBar->setSize(size);
            return hScrollBar;
        }
        else if (clsid == L"vscrollbar"){
            FCVScrollBar *vScrollBar = new FCVScrollBar;
            vScrollBar->setVisible(false);
            FCSize size = {10, 10};
            vScrollBar->setSize(size);
            return vScrollBar;
        }
    }
    FCGrid *grid = dynamic_cast<FCGrid*>(parent);
    if(grid){
        if(clsid == L"edittextbox"){
            return new FCTextBox;
        }
    }
    return 0;
}

FCSize IOSHost::getClientSize(){
    FCSize size ={0};
    if(m_view){
        size = getSize(m_view.frame.size);
    }
    return size;
}

FCCursors IOSHost::getCursor(){
    FCCursors retCursorsStyle = FCCursors_Arrow;
    NSCursor *currentCursor = [NSCursor currentCursor];
    if(currentCursor == [NSCursor arrowCursor]){
        //
    }
    else if(currentCursor == [NSCursor closedHandCursor]){
        retCursorsStyle = FCCursors_ClosedHand;
    }
    else if(currentCursor == [NSCursor crosshairCursor]){
        retCursorsStyle = FCCursors_Cross;
    }
    else if(currentCursor == [NSCursor disappearingItemCursor]){
        retCursorsStyle = FCCursors_DisappearingItem;
    }
    else if(currentCursor == [NSCursor dragCopyCursor]){
        retCursorsStyle = FCCursors_DragCopy;
    }
    else if(currentCursor == [NSCursor dragLinkCursor]){
        retCursorsStyle = FCCursors_DragLink;
    }
    else if(currentCursor == [NSCursor openHandCursor]){
        retCursorsStyle = FCCursors_Hand;
    }
    else if(currentCursor == [NSCursor IBeamCursor]){
        retCursorsStyle = FCCursors_IBeam;
    }
    else if(currentCursor == [NSCursor IBeamCursorForVerticalLayout]){
        retCursorsStyle = FCCursors_IBeamCursorForVerticalLayout;
    }
    else if(currentCursor == [NSCursor operationNotAllowedCursor]){
        retCursorsStyle = FCCursors_No;
    }
    else if(currentCursor == [NSCursor pointingHandCursor]){
        retCursorsStyle = FCCursors_PointingHand;
    }
    else if(currentCursor == [NSCursor resizeDownCursor]){
        retCursorsStyle = FCCursors_SizeDown;
    }
    else if(currentCursor == [NSCursor resizeLeftCursor]){
        retCursorsStyle = FCCursors_SizeLeft;
    }
    else if(currentCursor == [NSCursor resizeLeftRightCursor]){
        retCursorsStyle = FCCursors_SizeRight;
    }
    else if(currentCursor == [NSCursor resizeUpCursor]){
        retCursorsStyle = FCCursors_SizeUp;
    }
    else if(currentCursor == [NSCursor resizeLeftRightCursor]){
        retCursorsStyle = FCCursors_SizeWE;
    }
    else if(currentCursor == [NSCursor resizeUpDownCursor]){
        retCursorsStyle = FCCursors_SizeNS;
    }
    else if(currentCursor == [[NSCursor class] performSelector:@selector(_windowResizeNorthEastSouthWestCursor)]){
        retCursorsStyle = FCCursors_SizeNESW;
    }
    else if(currentCursor == [[NSCursor class] performSelector:@selector(_windowResizeNorthWestSouthEastCursor)]){
        retCursorsStyle = FCCursors_SizeNWSE;
    }
    else if(currentCursor == [[NSCursor class] performSelector:@selector(_waitCursor)]){
        retCursorsStyle = FCCursors_WaitCursor;
    }
    return retCursorsStyle;
}

int IOSHost::getIntersectRect(FCRect *lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect)
{
    lpDestRect->left = max(lpSrc1Rect->left, lpSrc2Rect->left);
    lpDestRect->right = min(lpSrc1Rect->right, lpSrc2Rect->right);
    lpDestRect->top = max(lpSrc1Rect->top, lpSrc2Rect->top);
    lpDestRect->bottom = min(lpSrc1Rect->bottom, lpSrc2Rect->bottom);
    if(lpDestRect->right >= lpDestRect->left && lpDestRect->bottom >= lpDestRect->top){
        return 1;
    }
    else{
        lpDestRect->left = 0;
        lpDestRect->right = 0;
        lpDestRect->top = 0;
        lpDestRect->bottom = 0;
        return 0;
    }
}

FCPoint IOSHost::getTouchPoint(){
    FCPoint mp = m_mousePoint;
    if (m_native->allowScaleSize()){
        FCSize clientSize = getClientSize();
        if (clientSize.cx > 0 && clientSize.cy > 0){
            FCSize scaleSize = m_native->getScaleSize();
            mp.x = mp.x * scaleSize.cx / clientSize.cx;
            mp.y = mp.y * scaleSize.cy / clientSize.cy;
        }
    }
    return mp;
}

FCSize IOSHost::getSize(){
    if (m_native->allowScaleSize()){
        return m_native->getScaleSize();
    }
    else{
        return getClientSize();
    }
}

int IOSHost::getUnionRect(FCRect *lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect){
    return 0;
}

void IOSHost::invalidate(){
    [m_view setNeedsDisplay:true];
}

void IOSHost::invalidate(const FCRect& rect){
    if(m_allowPartialPaint){
        double scaleFactorX = 1, scaleFactorY = 1;
        FCSize clientSize = getClientSize();
        if (m_native->allowScaleSize()){
            if (clientSize.cx > 0 && clientSize.cy > 0){
                FCSize scaleSize = m_native->getScaleSize();
                scaleFactorX = (double)(clientSize.cx) / scaleSize.cx;
                scaleFactorY = (double)(clientSize.cy) / scaleSize.cy;
            }
        }
        FCRect newRect = rect;
        if(scaleFactorX != 1 || scaleFactorY != 1){
            newRect.left = floor(newRect.left * scaleFactorX);
            newRect.top = floor(newRect.top * scaleFactorY);
            newRect.right = ceil(newRect.right * scaleFactorX);
            newRect.bottom = ceil(newRect.bottom * scaleFactorY);
        }
        CGRect drawRect = getCGRect(newRect);
        drawRect.origin.y = clientSize.cy - newRect.top - (newRect.bottom - newRect.top);
        [m_view setNeedsDisplayInRect:drawRect];
    }
    else{
        invalidate();
    }
}

void IOSHost::invoke(FCView *view, void *args){
    if([NSThread isMainThread] == YES){
        view->onInvoke(args);
    }else{
        dispatch_sync(dispatch_get_main_queue(), ^{
            view->onInvoke(args);
        });
    }
}

bool IOSHost::isKeyPress(char key){
    NSUInteger flags = [[NSApp currentEvent] modifierFlags];
    if(key == 0x10){
        if (flags & NSShiftKeyMask){
            return true;
        }
    }else if(key == 0x11){
        if (flags & NSCommandKeyMask){
            return true;
        }
        if (flags & NSControlKeyMask){
            return true;
        }
    }else if(key == 0x12){
        if(flags & NSAlternateKeyMask){
            return true;
        }
    }
    return false;
}


void IOSHost::onPaint(const FCRect& rect){
    FCSize displaySize = m_native->getSize();
    double scaleFactorX = 1, scaleFactorY = 1;
    FCSize clientSize = getClientSize();
    if (m_native->allowScaleSize()){
        if (clientSize.cx > 0 && clientSize.cy > 0){
            FCSize scaleSize = m_native->getScaleSize();
            scaleFactorX = (double)(clientSize.cx) / scaleSize.cx;
            scaleFactorY = (double)(clientSize.cy) / scaleSize.cy;
        }
    }
    FCPaint *paint = m_native->getPaint();
    FCRect wRect = {0, 0, clientSize.cx, clientSize.cy};
    paint->setScaleFactor(scaleFactorX, scaleFactorY);
    FCRect clipRect = rect;
    if (clipRect.left < 0)
    {
        clipRect.left = 0;
    }
    if (clipRect.top < 0)
    {
        clipRect.top = 0;
    }
    if (clipRect.right * scaleFactorX > clientSize.cx)
    {
        clipRect.right = (int)(clientSize.cx / scaleFactorX);
    }
    if (clipRect.bottom * scaleFactorY > clientSize.cy)
    {
        clipRect.bottom = (int)(clientSize.cy / scaleFactorY);
    }
    paint->beginPaint(0, wRect, clipRect);
    m_native->onPaint(clipRect);
    if(m_view){
        FCUIView *uiView = (FCUIView*)m_view;
        String markedText = [uiView getMarkedText];
        if((int)markedText.length() > 0){
            FCPoint offset = {0, 0};
            paint->setOffset(offset);
            paint->setClip(clipRect);
            //绘制拼音
            FCView *focusedView = m_native->getFocusedView();
            if(focusedView){
                FCTextBox *textBox = dynamic_cast<FCTextBox*>(focusedView);
                if(textBox){
                    FCPoint cursorPoint = textBox->getCursorPoint();
                    int clientX = m_native->clientX(textBox) + cursorPoint.x;
                    int clientY = m_native->clientY(textBox) + cursorPoint.y;
                    FCSize tSize = paint->textSize(markedText, textBox->getFont());
                    FCRect tRect = {clientX, clientY, clientX + tSize.cx, clientY + tSize.cy};
                    paint->fillRect(textBox->getBackColor(), tRect);
                    FCDraw::drawText(paint, markedText, textBox->getTextColor(), textBox->getFont(), clientX, clientY);
                }
            }
        }
    }
    paint->endPaint();
}

void IOSHost::onTimer(){
    if(m_native){
        if(m_isViewAppear){
            ArrayList<int> timerIDs;
            map<int, IOSTimer*>::iterator sIter = m_timers.begin();
            for(; sIter != m_timers.end(); ++sIter){
                IOSTimer *timer = sIter->second;
                if (timer->m_tick % timer->m_interval == 0){
                    timerIDs.add(timer->m_timerID);
                    
                }
                timer->m_tick++;
            }
            for(int i = 0; i < timerIDs.size(); i++){
                m_native->onTimer(timerIDs.get(i));
            }
            timerIDs.clear();
        }
    }
}

string IOSHost::paste(){
    NSPasteboard *pasteboard = [NSPasteboard generalPasteboard];
    if(pasteboard){
        if ([[pasteboard types] containsObject:NSPasteboardTypeString]) {
            NSString *str = [pasteboard stringForType:NSPasteboardTypeString];
            if(str){
                return [str UTF8String];
            }
        }
    }
    return "";
}

void IOSHost::setAllowOperate(bool allowOperate){
    m_allowOperate = allowOperate;
}

void IOSHost::setAllowPartialPaint(bool allowPartialPaint){
    m_allowPartialPaint = allowPartialPaint;
}

void IOSHost::setCursor(FCCursors cursor){
    NSCursor *targetCursor = nil;
    switch (cursor) {
        case FCCursors_Arrow:
            targetCursor = [NSCursor arrowCursor];
            break;
        case FCCursors_ClosedHand:
            targetCursor = [NSCursor closedHandCursor];
            break;
        case FCCursors_Cross:
            targetCursor = [NSCursor crosshairCursor];
            break;
        case FCCursors_DisappearingItem:
            targetCursor = [NSCursor disappearingItemCursor];
            break;
        case FCCursors_DragCopy:
            targetCursor = [NSCursor dragCopyCursor];
            break;
        case FCCursors_DragLink:
            targetCursor = [NSCursor dragLinkCursor];
            break;
        case FCCursors_Hand:
            targetCursor = [NSCursor openHandCursor];
            break;
        case FCCursors_IBeam:
            targetCursor = [NSCursor IBeamCursor];
            break;
        case FCCursors_IBeamCursorForVerticalLayout:
            targetCursor = [NSCursor IBeamCursorForVerticalLayout];
            break;
        case FCCursors_No:
            targetCursor = [NSCursor operationNotAllowedCursor];
            break;
        case FCCursors_PointingHand:
            targetCursor = [NSCursor pointingHandCursor];
            break;
        case FCCursors_SizeDown:
            targetCursor = [NSCursor resizeDownCursor];
            break;
        case FCCursors_SizeLeft:
            targetCursor = [NSCursor resizeLeftCursor];
            break;
        case FCCursors_SizeRight:
            targetCursor = [NSCursor resizeLeftRightCursor];
            break;
        case FCCursors_SizeUp:
            targetCursor = [NSCursor resizeUpCursor];
            break;
        case FCCursors_SizeWE:
            targetCursor = [NSCursor resizeLeftRightCursor];
            break;
        case FCCursors_SizeNS:
            targetCursor = [NSCursor resizeUpDownCursor];
            break;
        case FCCursors_SizeNESW:
            targetCursor = [[NSCursor class] performSelector:@selector(_windowResizeNorthEastSouthWestCursor)];
            break;
        case FCCursors_SizeNWSE:
            targetCursor = [[NSCursor class] performSelector:@selector(_windowResizeNorthWestSouthEastCursor)];
            break;
        case FCCursors_WaitCursor:
            targetCursor = [[NSCursor class] performSelector:@selector(_waitCursor)];
            break;
    }
    NSCursor *currentCursor = [NSCursor currentCursor];
    if(targetCursor && targetCursor != currentCursor){
        [targetCursor set];
    }
}

void IOSHost::setTouchPoint(const FCPoint& mp){
    m_mousePoint = mp;
}

void IOSHost::startTimer(int timerID, int interval)
{
    interval = interval / 10;
    if(interval < 1){
        interval = 1;
    }
    //m_lock.lock();
    map<int, IOSTimer*>::iterator sIter = m_timers.find(timerID);
    if(sIter != m_timers.end()){
        sIter->second->m_interval = interval;
        sIter->second->m_tick = 0;
    }
    else{
        IOSTimer *timer = new IOSTimer;
        timer->m_interval = interval;
        timer->m_timerID = timerID;
        m_timers[timerID] = timer;
    }
    //m_lock.unLock();
}

void IOSHost::stopTimer(int timerID){
    //m_lock.lock();
    map<int, IOSTimer*>::iterator sIter = m_timers.find(timerID);
    if(sIter != m_timers.end()){
        delete sIter->second;
        m_timers.erase(sIter);
    }
    //m_lock.unLock();
}

/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef FCLOCK_h
#define FCLOCK_h

/*
 * 同步锁
 */
class FCLock{
public:
    /*
     * 构造函数
     */
    FCLock(){
        mutex_x = PTHREAD_MUTEX_INITIALIZER;
    }
    /*
     * 析构函数
     */
    virtual ~FCLock(){
    }
    /*
     * 锁
     */
    void lock(){
        pthread_mutex_lock(&mutex_x);
    }
    /*
     * 解锁
     */
    void unLock(){
        pthread_mutex_unlock(&mutex_x);
    }
private:
    pthread_mutex_t mutex_x;
};

#endif 

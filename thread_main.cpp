#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#include "thread_main.h"

#include <opencv2/opencv.hpp>

void *thread_func(void *param);
// int thread_main(void) {

//     cv::VideoCapture cap(0);

//     if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
//     {
//         //読み込みに失敗したときの処理
//         return -1;
//     }

//     cv::Mat frame; //取得したフレーム
//     cap.read(frame);
//     cv::imwrite("img.png", frame);
// }
sigset_t current_sigset;

int thread_main(void) {

    pthread_t thread;
    int ret = 0;

    printf("thread_main 1\n");

    disable_interrupt(&current_sigset);
    printf("thread_main 2\n");
        // cv::Mat frame; //取得したフレーム
        // frame = cv::imread("sample.png",1);

    // スレッドの作成
    // int pthread_create(pthread_t * thread, pthread_attr_t * attr,
    //                    void * (*start_routine)(void *), void * arg)
    // 第4引数に渡した値が、スレッド関数の引数に渡される
    ret = pthread_create(&thread, NULL, thread_func, NULL);
    if (ret != 0) {
        // pthread_createが失敗した場合は0以外の値を返す
        exit(1);
    }
        printf("thread_main 3\n");

    // スレッドの終了を待機
    // int pthread_join(pthread_t th, void **thread_return)
    ret = pthread_join(thread, NULL);
    if (ret != 0) {
        // pthread_joinが失敗した場合は0以外の値を返す
        exit(1);
    }
        printf("thread_main 4\n");

    
    // スレッドの終了を待たない
    // int pthread_detach(pthread_t th)
    // ret = pthread_detach(thread);
    // if (ret != 0) {
    //     // pthread_detachが失敗した場合は0以外の値を返す
    //     exit(1);
    // }
    
     enable_interrupt(&current_sigset);
           printf("thread_main 5\n");

    return EXIT_SUCCESS;
}

void *thread_func(void *param)
{
    // 非同期に実行する処理
    // while(1) {
    //     printf("exec thread\n");
    //     usleep(1000*1000);
    // }
    //     printf("exec thread\n");
    // cv::VideoCapture cap(0);
    //     printf("exec thread2\n");

    // if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    // {
    //     //読み込みに失敗したときの処理
    //         printf("fail\n");

    // }
    // else {
    //     cv::Mat frame; //取得したフレーム
    //     cap.read(frame);
    //     cv::imwrite("img.png", frame);
    // }

        // cv::Mat frame; //取得したフレーム
        // frame = cv::imread("sample.png",1);
        // cv::imwrite("img.png", frame);

     return (void*)0;
}

void disable_interrupt(sigset_t *old)
{
  sigset_t sigset;
  sigemptyset(&sigset);

  sigaddset(&sigset,SIGUSR2);
  sigaddset(&sigset,SIGALRM);
  sigaddset(&sigset,SIGPOLL);
  pthread_sigmask(SIG_BLOCK, &sigset, old);
  return;
}

void enable_interrupt(sigset_t *to_set)
{
  pthread_sigmask(SIG_SETMASK,to_set,NULL);
}



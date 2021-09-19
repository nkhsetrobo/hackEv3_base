#include "Area.h"
#include "BingoEnum.h"
#include "CrossCircle.h"
#include "BlockCircle.h"
#include "BlackLine.h"

#include "util.h"
#include "etroboc_ext.h"

Area::Area(int idx)
{   
    course = idx; 
   // course=0; // L:0 R:1
    //bonus=2;
    bonus=1;

    int bk[] = {1,3,5, 7,9,11,13, 15,17,19, 21,23,25,27, 29,31,33, 35,37,39,41, 43,45,47};
    //黒線
    for (int i=0;i<24;i++)
        bp[bk[i]] = new BlackLine(bk[i]);
    bp[24]=nullptr;

    if(course==0) {
    //Lコースマップ
        exit[0] = 28;
        exit[1] = -1; //出るなら28

        bp[0] =new CrossCircle(0,1,COLOR::RED);
        bp[2] =new CrossCircle(2,2,COLOR::RED);
        bp[4] =new CrossCircle(4,3,COLOR::BLUE);
        bp[6] =new CrossCircle(6,4,COLOR::BLUE);

        bp[14] =new CrossCircle(14,5,COLOR::RED);
        bp[16] =new CrossCircle(16,6,COLOR::RED);
        bp[18] =new CrossCircle(18,7,COLOR::BLUE);
        bp[20] =new CrossCircle(20,8,COLOR::BLUE);

        bp[28] =new CrossCircle(28,9,COLOR::YELLOW);
        bp[30] =new CrossCircle(30,10,COLOR::YELLOW);
        bp[32] =new CrossCircle(32,11,COLOR::GREEN);
        bp[34] =new CrossCircle(34,12,COLOR::GREEN);

        bp[42] =new CrossCircle(42,13,COLOR::YELLOW);
        bp[44] =new CrossCircle(44,14,COLOR::YELLOW);
        bp[46] =new CrossCircle(46,15,COLOR::GREEN);
        bp[48] =new CrossCircle(48,16,COLOR::GREEN);

        bp[8] = new BlockCircle(8,1,COLOR::YELLOW);
        bp[10] = new BlockCircle(10,2,COLOR::GREEN);
        bp[12] = new BlockCircle(12,3,COLOR::RED);
        bp[22] = new BlockCircle(22,4,COLOR::BLUE);
        bp[26] = new BlockCircle(26,5,COLOR::YELLOW);
        bp[36] = new BlockCircle(36,6,COLOR::GREEN);
        bp[38] = new BlockCircle(38,7,COLOR::RED);
        bp[40] = new BlockCircle(40,8,COLOR::BLUE);

        // 走行体初期化
        runner = new Runner();
        runner->setStart(bp[30]);
        runner->setEnd(bp[30]);
        runner->setDir(DIR::S);


    }
    //Rコースマップ
    else if(course==1) {
        exit[0] = 14;
        //exit[0] = 0; //お試し
       exit[1] = -1; //出るなら28

        bp[0] =new CrossCircle(0,1,COLOR::BLUE);
        bp[2] =new CrossCircle(2,2,COLOR::BLUE);
        bp[4] =new CrossCircle(4,3,COLOR::RED);
        bp[6] =new CrossCircle(6,4,COLOR::RED);

        bp[14] =new CrossCircle(14,5,COLOR::BLUE);
        bp[16] =new CrossCircle(16,6,COLOR::BLUE);
        bp[18] =new CrossCircle(18,7,COLOR::RED);
        bp[20] =new CrossCircle(20,8,COLOR::RED);

        bp[28] =new CrossCircle(28,9,COLOR::GREEN);
        bp[30] =new CrossCircle(30,10,COLOR::GREEN);
        bp[32] =new CrossCircle(32,11,COLOR::YELLOW);
        bp[34] =new CrossCircle(34,12,COLOR::YELLOW);

        bp[42] =new CrossCircle(42,13,COLOR::GREEN);
        bp[44] =new CrossCircle(44,14,COLOR::GREEN);
        bp[46] =new CrossCircle(46,15,COLOR::YELLOW);
        bp[48] =new CrossCircle(48,16,COLOR::YELLOW);

        bp[8] = new BlockCircle(8,1,COLOR::RED);
        bp[10] = new BlockCircle(10,2,COLOR::GREEN);
        bp[12] = new BlockCircle(12,3,COLOR::YELLOW);
        bp[22] = new BlockCircle(22,4,COLOR::YELLOW);
        bp[26] = new BlockCircle(26,5,COLOR::BLUE);
        bp[36] = new BlockCircle(36,6,COLOR::BLUE);
        bp[38] = new BlockCircle(38,7,COLOR::RED);
        bp[40] = new BlockCircle(40,8,COLOR::GREEN);

        // 走行体初期化
        runner = new Runner();
        runner->setStart(bp[46]);
        runner->setEnd(bp[46]);
        runner->setDir(DIR::S);

    }

        // サークル同士の関連
    //交点サークル->ブロックサークル
    bp[0]->setSlashPlace(nullptr,bp[8],nullptr,nullptr);
    bp[2]->setSlashPlace(nullptr,bp[10],bp[8],nullptr);
    bp[4]->setSlashPlace(nullptr,bp[12],bp[10],nullptr);
    bp[6]->setSlashPlace(nullptr,nullptr,bp[12],nullptr);
    bp[14]->setSlashPlace(bp[8],bp[22],nullptr,nullptr);
    bp[16]->setSlashPlace(bp[10],bp[24],bp[22],bp[8]);
    bp[18]->setSlashPlace(bp[12],bp[26],bp[24],bp[10]);
    bp[20]->setSlashPlace(nullptr,nullptr,bp[26],bp[12]);
    bp[28]->setSlashPlace(bp[22],bp[36],nullptr,nullptr);
    bp[30]->setSlashPlace(bp[24],bp[38],bp[36],bp[22]);
    bp[32]->setSlashPlace(bp[26],bp[40],bp[38],bp[24]);
    bp[34]->setSlashPlace(nullptr,nullptr,bp[40],bp[26]);
    bp[42]->setSlashPlace(bp[36],nullptr,nullptr,nullptr);
    bp[44]->setSlashPlace(bp[38],nullptr,nullptr,bp[36]);
    bp[46]->setSlashPlace(bp[40],nullptr,nullptr,bp[38]);
    bp[48]->setSlashPlace(nullptr,nullptr,nullptr,bp[40]);
    // ブロックサークル->交点サークル
    bp[8]->setSlashPlace(bp[2],bp[16],bp[14],bp[0]);
    bp[10]->setSlashPlace(bp[4],bp[18],bp[16],bp[2]);
    bp[12]->setSlashPlace(bp[6],bp[20],bp[18],bp[4]);
    bp[22]->setSlashPlace(bp[16],bp[30],bp[28],bp[14]);
    bp[26]->setSlashPlace(bp[20],bp[34],bp[32],bp[18]);
    bp[36]->setSlashPlace(bp[30],bp[44],bp[42],bp[28]);
    bp[38]->setSlashPlace(bp[32],bp[46],bp[44],bp[30]);
    bp[40]->setSlashPlace(bp[34],bp[48],bp[46],bp[32]);



    setDefaultBlock();
}

void Area::setDefaultBlock()
{
    // ブロック初期化
   /* 
    bp[0]->addBlock(new Block(COLOR::NONE));
    bp[4]->addBlock(new Block(COLOR::NONE));
    bp[16]->addBlock(new Block(COLOR::NONE));
    bp[20]->addBlock(new Block(COLOR::NONE));
    bp[28]->addBlock(new Block(COLOR::NONE));
    bp[32]->addBlock(new Block(COLOR::NONE));
    bp[44]->addBlock(new Block(COLOR::NONE));
    bp[48]->addBlock(new Block(COLOR::NONE));
    */
  
    // test 9/14
    bp[2]->addBlock(new Block(COLOR::GREEN));
    bp[6]->addBlock(new Block(COLOR::BLUE));
    bp[14]->addBlock(new Block(COLOR::RED));
    bp[18]->addBlock(new Block(COLOR::YELLOW));
    bp[30]->addBlock(new Block(COLOR::RED));
    bp[34]->addBlock(new Block(COLOR::YELLOW));
    bp[42]->addBlock(new Block(COLOR::BLUE));
    bp[46]->addBlock(new Block(COLOR::GREEN));

    
    // デバッグ用のデフォルト値
    //bp[32]->addBlock(new Block(COLOR::RED));
    //bp[0]->addBlock(new Block(COLOR::BLUE));
    //bp[4]->addBlock(new Block(COLOR::BLUE));
    //bp[28]->addBlock(new Block(COLOR::YELLOW));
/*
    bp[0]->addBlock(new Block(COLOR::RED));
    bp[4]->addBlock(new Block(COLOR::BLUE));
    bp[16]->addBlock(new Block(COLOR::YELLOW));
    bp[20]->addBlock(new Block(COLOR::RED));
    bp[28]->addBlock(new Block(COLOR::GREEN));
    bp[32]->addBlock(new Block(COLOR::BLUE));
    bp[44]->addBlock(new Block(COLOR::BLACK));
    bp[48]->addBlock(new Block(COLOR::YELLOW));
*/
    //bp[40]->addBlock(new Block(COLOR::BLACK));


//    if(course==0){
/*  //L即スローイン
    bp[0]->addBlock(new Block(COLOR::YELLOW));
    bp[4]->addBlock(new Block(COLOR::RED));
    bp[16]->addBlock(new Block(COLOR::GREEN));
    bp[20]->addBlock(new Block(COLOR::YELLOW));
    bp[28]->addBlock(new Block(COLOR::BLUE));
    bp[32]->addBlock(new Block(COLOR::RED));
    bp[44]->addBlock(new Block(COLOR::GREEN));
    bp[48]->addBlock(new Block(COLOR::BLUE));
*/
//    }else{
  //R即スローイン
  /*
    bp[0]->addBlock(new Block(COLOR::RED));
    bp[4]->addBlock(new Block(COLOR::YELLOW));
    bp[16]->addBlock(new Block(COLOR::GREEN));
    bp[20]->addBlock(new Block(COLOR::BLUE));
    bp[28]->addBlock(new Block(COLOR::YELLOW));
    bp[32]->addBlock(new Block(COLOR::RED));
    bp[44]->addBlock(new Block(COLOR::BLUE));
    bp[48]->addBlock(new Block(COLOR::GREEN));
*/

 /* 
    bp[0]->addBlock(new Block(COLOR::RED));
    bp[4]->addBlock(new Block(COLOR::BLUE));
    bp[16]->addBlock(new Block(COLOR::YELLOW));
    bp[20]->addBlock(new Block(COLOR::RED));
    bp[28]->addBlock(new Block(COLOR::GREEN));
    bp[32]->addBlock(new Block(COLOR::BLUE));
    bp[44]->addBlock(new Block(COLOR::BLACK));
    bp[48]->addBlock(new Block(COLOR::YELLOW));
 */
    // debug用ブロックサークル用初期値
   // bp[26]->addBlock(new Block(COLOR::YELLOW));
    //bp[38]->addBlock(new Block(COLOR::GREEN));
   
}


void Area::modifyBlockColor(int no,COLOR col )
{
    int cross_list[] = {0,2,4,6, 14,16,18,20, 28,30,32,34, 42, 44, 46,48};
    int block_list[] = {8,10,12,22,26,36,38,40}; 
    if (no==0) return;
    if(no>24) return;

    int node;

    
    if(no<=16) {
      //  msg_f("mod block",9);
        node = cross_list[no-1];
    
        Block *bk = bp[node]->getBlock();
        if(bk!=nullptr)
            bk->setColor(col);
    } else {
       // msg_f("mod block c",10);
        
        node = block_list[no-17];
        bp[node]->addBlock(new Block(col));        
    }
}

void Area::modifyBlockColorByNodeId(int nodeid,COLOR col)
{
    Block *bk = bp[nodeid]->getBlock();
    if(bk!=nullptr)
        bk->setColor(col);

}

BlockPlace *Area::getBlockPlace(int idx)
{
    return bp[idx];
}

void Area::getBlockList(int node[])
{
    static char buf[256];

    int cnt=0;
    for(int i=0;i<49;i++) {
        if (bp[i]!=nullptr && bp[i]->getBlock()!=nullptr) {

            // ブロックサークル内に同色がある場合は動かす必要なし
            if(bp[i]->getKind()==BPKIND::BLOCK) {
                BlockCircle* bc = (BlockCircle*)bp[i];
                if(bc->getColor()==bc->getBlock()->getColor())
                    continue;
                if(bc->getBlock()->getColor()==COLOR::BLACK && bc->getid() == bonus)  // 黒がボーナスサークルと一致している場合は動かさない
                    continue;
            }
            node[cnt++]=i;
        }
    }
    node[cnt]=-1;
}

Runner* Area::getRunner()
{
    return runner;
}

Block* Area::getBlock(int id)
{
    Block* bk = bp[id]->getBlock();
    bp[id]->delBlock();

    return bk;
}

void Area::setBlock(int id,Block *bk)
{
    bp[id]->addBlock(bk);
}

void Area::setBonusNo(int no)
{
    if (no==0) return;
    bonus = no;
}

int Area::getBonusNo()
{
    return bonus;
}

int Area::remainBlock()
{
    static char buf[256];

    int cross_list [] = {0,2,4,8, 14,16,18,20, 28,30,32,34, 42,44,46,48};
    int block_circle_list[8] = {8,10,12, 22, 26, 36,38,40};
    int cnt=0;
    for (int i=0;i<49;i++) {
         if(bp[i]!=nullptr && bp[i]->getKind()!=BLOCK) {
             if(bp[i]->getBlock()!=nullptr) {
               // sprintf(buf,"remain %d:%d",i,bp[i]->getBlock()->getColor());
               // msg_f(buf,12);
                cnt++;
            }
         }
    }

    for(int i=0;i<8;i++) {
        BlockCircle *bc = (BlockCircle*)bp[block_circle_list[i]];
        if(bc->getBlock()!=nullptr && bc->getBlock()->getColor()==COLOR::BLACK && bc->getid()!=bonus) // 黒でボーナスサークル以外なら移動対象
            cnt++;
    }


    return cnt;
}

void Area::getExitList(int ex[])
{
    ex[0] = exit[0];
    ex[1] = exit[1];
}

void Area::cleanBlocks()
{
    for(int i=0;i<49;i++) {
        if(bp[i]!=nullptr)
            bp[i]->resetBlock();
    }
}

void Area::assignBlockList()
{
    Block *block;
    for(int i=0;i<5;i++)
        assign[i]=0;

    for(int i=0;i<49;i++) {
        if(bp[i]!=nullptr && (block=bp[i]->getBlock())!=nullptr) {
            assign[(int)block->getColor()]++;
        }
    }

}

int *Area::getAssingPointer()
{
    return assign;
}

void Area::getBlockCircles(COLOR col, int idxs[])
{
    int node2idx[49];
    node2idx[8]= 0;
    node2idx[10] = 1;
    node2idx[12] = 2;
    node2idx[22] = 3;
    node2idx[26] = 4;
    node2idx[36] = 5;
    node2idx[38] = 6;
    node2idx[40] = 7;

    int cnt=0;
    for(int i=0;i<49;i++) {
        if(bp[i]->getKind()==BPKIND::BLOCK) {
            if( ((BlockCircle*)bp[i])->getColor()==col) {
                if(bp[i]->getBlock()==nullptr) {
                   // printf("THIS PLACE IS EMPTY %d\n",i);
                    idxs[cnt++]=node2idx[i];
                }
            }
        }
    }
    idxs[cnt]=-1;
}

void Area::getBlockListIdxs(int node[])
{
    int node2idx[49]= {0,-1,1,-1,2,-1,3,
                     -1,-1,-1,-1,-1,-1,-1, 
                    4,-1,5,-1,6,-1,7, 
                    -1,-1,-1,-1,-1,-1,-1, 
                    8,-1,9,-1,10,-1,11, 
                    -1,-1,-1,-1,-1,-1,-1,  
                    12,-1,13,-1,14,-1,15 };

    getBlockList(node);
    for(int i=0;node[i]!=-1;i++ ) {
        node[i] = node2idx[node[i]];
    }

}

void Area::initBlockFromApi()
{
    int lookup[100];
    lookup['A'] = 0;
    lookup['B'] = 2;
    lookup['C'] = 4;
    lookup['D'] = 6;

    lookup['E'] = 14;
    lookup['F'] = 16;
    lookup['G'] = 18;
    lookup['H'] = 20;

    lookup['J'] = 28;
    lookup['K'] = 30;
    lookup['L'] = 32;
    lookup['M'] = 34;

    lookup['P'] = 42;
    lookup['Q'] = 44;
    lookup['R'] = 46;
    lookup['S'] = 48;

    int red1 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED1);
    int red2 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED2);
    int green1 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1);
    int green2 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2);
    int blue1 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1);
    int blue2 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2);
    int yellow1 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1);
    int yellow2 = ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2);

    // bp[lookup[red1]]->getBlock()->setColor(COLOR::RED);
    // bp[lookup[red2]]->getBlock()->setColor(COLOR::RED);
    // bp[lookup[green1]]->getBlock()->setColor(COLOR::GREEN);
    // bp[lookup[green2]]->getBlock()->setColor(COLOR::GREEN);
    // bp[lookup[blue1]]->getBlock()->setColor(COLOR::BLUE);
    // bp[lookup[blue2]]->getBlock()->setColor(COLOR::BLUE);
    // bp[lookup[yellow1]]->getBlock()->setColor(COLOR::YELLOW);
    // bp[lookup[yellow2]]->getBlock()->setColor(COLOR::YELLOW);

    modifyBlockColorByNodeId(lookup[red1],COLOR::RED);
    modifyBlockColorByNodeId(lookup[red2],COLOR::RED);
    modifyBlockColorByNodeId(lookup[green1],COLOR::GREEN);
    modifyBlockColorByNodeId(lookup[green2],COLOR::GREEN);
    modifyBlockColorByNodeId(lookup[blue1],COLOR::BLUE);
    modifyBlockColorByNodeId(lookup[blue2],COLOR::BLUE);
    modifyBlockColorByNodeId(lookup[yellow1],COLOR::YELLOW);
    modifyBlockColorByNodeId(lookup[yellow2],COLOR::YELLOW);
    
}

#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
using namespace std;

/*结构体数组，用来保存各个考生相关信息*/
struct Student
{
    int location_num;
    LL id;
    int score;
    int local_rank;
    int final_rank;
}stu[30010];

bool cmp(Student a, Student b){
    if(a.score!=b.score){
        return a.score>b.score;//按分数降序
    }
    else{
        return a.id<b.id;//非降序
    }
    
}

int main(){
    int n, k, num = 0;
    scanf("%d", &n);    //考场数n

    for(int i = 1; i<=n; i++){//逐个读取每个考场考生
        scanf("%d", &k);//考生数
        for(int j = 1; j<=k; j++){
            stu[num].location_num = i;
            scanf("%lld%d", &stu[num].id, &stu[num].score);
            num++;  //共num个考生
        }
        //读完一个考场，先排序得到本地排名
        sort(stu+num-k, stu+num, cmp);
        stu[num-k].local_rank = 1;//第一个本地排名为1
        for(int j = num-k+1; j < num; j++){
        
            if(stu[j].score == stu[j-1].score){
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else{
                stu[j].local_rank = j+1-(num-k);
            }
        }
        
    }
    sort(stu, stu+num, cmp);
    printf("%d\n", num);
    stu[0].final_rank = 1;
    for(int i = 1; i < num; i++){
        if(stu[i].score == stu[i-1].score){
            stu[i].final_rank = stu[i-1].final_rank;
        }
        else{
            stu[i].final_rank = i+1;
        }
        
    }

    for(int i = 0; i < num; i++){
        printf("%013lld %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_num, stu[i].local_rank);
    }
    

    
    return 0;
    
}
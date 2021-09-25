#include <bits\stdc++.h>
using namespace std ;
const int MAX_N = 200 ;

int id[MAX_N * MAX_N + 1] ; 
int sz[MAX_N * MAX_N + 1] ;   //树高
bool isopen[MAX_N * MAX_N + 1] ;  //是否为opensite
int N ;

void init() {
    for(int p = 1 ; p <= N * N ; p++) {
        id[p] = p ;
        sz[p] = 0 ;
        isopen[p] = false ;
    }
}

int find(int i,int j) {
    int p = (i - 1) * N + j ;
    while(id[p] != p) {
        p = id[p] ;
    }
    return p ;
}

void unite(int i1,int j1,int i2,int j2) {
    int qid = find(i1 , j1);
    int pid = find(i2 , j2);
    if(qid == pid) return ;
    if(qid >= 1 && qid <= N) {
        id[pid] = qid ;
        sz[qid] ++ ;
        return ;
    } 
    if(pid >= 1 && pid <= N) {
        id[qid] = pid ;
        sz[pid] ++ ;
        return ;
    }
    if(sz[qid] == sz[pid]) {
        id[pid] = qid ;
        sz[qid] ++ ;
    } else {
        if(sz[qid] > sz[pid]) {
            id[pid] = qid ;
        } else {
            id[qid] = pid ;
        }
    }
}

void open(int i,int j) {
    int p = (i - 1) * N + j ;
    isopen[p] = true ;
    if(i > 1 && isopen[p - N]) unite(i , j , i - 1 , j) ;
    if(i < N && isopen[p + N]) unite(i , j , i + 1 , j) ;
    if(j > 1 && isopen[p - 1]) unite(i , j , i , j - 1) ;
    if(j < N && isopen[p + 1]) unite(i , j , i , j + 1) ;
}

bool isfullopensite(int i,int j) {            //判断是否是full opensite
    if(!isopen[(i - 1) * N + j]) return false ;
    int position = find(i , j) ;
    if(position >= 1 && position <= N) return true ;
    return false ;
}

bool ispercolation() {             //判断是否渗透
    int x = N ;
    for(int y = 1 ; y <= N ; y++) {
        if(isfullopensite(x , y)) return true ; 
    }
    return false ;
}

int main() {
    clock_t start , end ;
    srand(time(0)) ;
    int times = 1 ;
    int cnt = 0 ;
    cin >> N ;start = clock() ;
    for(int i = 0 ; i < times ; i++) {
        init() ;
        vector <int> points_still_close ;
        for(int j = 1 ; j < N * N ; j++) {
            points_still_close.push_back(j) ;
        }
        while(!ispercolation()) {
            int index = rand() % points_still_close.size() ;
            int num = points_still_close[index] ;
            points_still_close.erase(points_still_close.begin() + index) ;
            int x = num / N + 1 ;
            int y = num % N ;
            open(x , y) ;
            cnt ++ ;
        }
    }
    end = clock() ;
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    printf("%.3f\n" , cnt * 1.0 / (times * N * N)) ;
    return 0 ;
}
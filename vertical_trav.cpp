/*
    Given a binary tree, find vertical sum;
*/

#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d):data(d),left(NULL),right(NULL){
        }
};

class bntree{

    public:

        node* make_btree(const vector<int> &vr, int n);

        void vtrav(node* root);

        void help_sum(node* root , map<int, vector<int> > &mp , int level);
        

};


int main(){

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    vector<int> vr(n,0);
    
    cout<<"Enter data of nodes in level order format;\nEnter -1 for NULL: ";
    for(int i=0;i<n;++i){
        cin>>vr[i];
    }

    bntree bnt;
    node* root = bnt.make_btree( vr , n );

    bnt.vtrav(root);
    
    return 0;
}

node* bntree::make_btree(const vector<int> &vr , int n){

    node* head = NULL;
    queue<node*> q;

    for(int i=0; i < n; ++i){

        if(q.empty()){
            head = new node(vr[i]);
            q.push(head);
        }
        else{
            node* curr = q.front();

            if(curr->left == NULL){
                if(vr[i] != -1){
                    curr->left = new node(vr[i]);
                    q.push(curr->left);
                }
            }

            ++i;
            if(i==n){
                break;
            }

            if(curr->right == NULL){
                if(vr[i] != -1){
                    curr->right = new node(vr[i]);
                    q.push(curr->right);
                }
                q.pop();
            }


        }
    }
    return head;
}

void bntree::vtrav(node* root){
    map<int,vector<int>> mp;

    help_sum(root , mp,0);

    map<int,vector<int>> :: iterator it1 = mp.begin();
    cout<<"Vertical sum is:\n";
    for( ; it1 != mp.end() ; ++it1){

        for(int i = 0 ; i < it1->second.size() ; ++i){
            cout<<it1->second[i]<<" ";
        }
        cout<<endl;

    }
    return ;

}

void bntree::help_sum(node* root , map<int,vector<int>> &mp, int level){
    
    if(root == NULL){
        return ;
    }

    mp[level].push_back(root->data);

    help_sum(root->left , mp , level-1);
    help_sum(root->right , mp , level+1);
}



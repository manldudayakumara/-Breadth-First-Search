#include<stdio.h>
#include<string.h>

#define MAX_N 100
#define MAX_E (MAX_N*(MAX_N-1))/2

int main(){
    int count=0;
    char type[20];
    char node[MAX_N];
    int weight[MAX_E];
    char edge[MAX_E][2];
    char visited[MAX_N];
    char queue[MAX_N];

    FILE *fp = fopen("graph.txt", "r");
    if (!fp) {
        printf("Error: Could not open graph.txt\n");
        return 1;
    }

    fscanf(fp, "%d", &count);   

    for(int i=0; i<count; i++){
         fscanf(fp, " %c", &node[i]);
	 printf("%c ",node[i]);
    }
    fscanf(fp, "%s", type);
    printf("\n%s \n",type);

    char n1,n2;
    int w=0, n_e=0,t_w=0;
    while(fscanf(fp, " %c %c %d", &n1, &n2, &w) == 3){
        edge[n_e][0] = n1;
        edge[n_e][1] = n2;
        weight[n_e] = w;
	printf("%c %c %d \n",edge[n_e][0],edge[n_e][1],weight[n_e]);
        n_e++;	
    }

    printf("BFS Traversal Path: ");
    
    //bfs traversal
    int head=0, tail = 1;
    queue[head] = edge[0][0];
      
    while(head != tail){    
    	for(int i=0; i<n_e; i++){
    		if(queue[head] == edge[i][0]){
			int v=0;
			for(int x=0; x<(tail+1); x++){
				if(edge[i][1] == queue[x]){
					v=1;
					break;
				}
			}
			if(v==0){
				queue[tail]= edge[i][1];
				tail++;
				t_w = t_w + weight[i];
			}
		}
		if(queue[head] == edge[i][1] && strcmp(type, "undirected")==0){
                	int v=0;
                	for(int x=0; x<(tail+1); x++){
                        	if(edge[i][0] == queue[x]){
                                	v=1;
                                	break;
                        	}
                	}
                	if(v==0){
                        	queue[tail]= edge[i][0];
                        	tail++;
				t_w = t_w + weight[i];
                	}
        	}
    	}
    	visited[head]=queue[head];
	printf("%c ",queue[head]);
	head++;
	if(head != tail) printf("-> ");
    }

    printf("\nTotal Weight = %d \n",t_w);
    printf("Unreachable Nodes: ");
	
    int v=0,f=0;
    for(int i=0; i<count; i++){
        v=0;
        for(int x=0; x<(head+1); x++){
            if(node[i]==visited[x]){
                v = 1;
                f=1;
		break;
            }
        }
        if(v==0){
            printf("%c ",node[i]);
        }
    }
    if(f==0) printf("none");
    printf("\n");
    
    fclose(fp);
} 

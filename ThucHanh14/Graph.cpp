#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <cstring>

using namespace std;



class Graph {
public:
    Graph() {
        edge = NULL;
        noVertices = 0;
        noEdges = 0;
    }
    Graph (int N) {
        noVertices = N;
        noEdges = 0;
        edge = new bool * [noVertices];
        for (int i = 0; i < noVertices; i++) {
            edge[i] = new bool[noVertices];
            for (int j = 0; j < noVertices; j++) {
                edge[i][j] = false;
            }
        }
    }
    ~Graph () {
        for (int i = 0; i < noVertices; i++) {
            delete [] edge[i];
        }
        delete [] edge;
        edge = NULL;
        noVertices = 0;
        noEdges = 0;
    }
    void randomGenerate(int N) {
        noVertices = N;
        noEdges = 0;
        edge = new bool * [noVertices];
        for (int i = 0; i < noVertices; i++) {
            edge[i] = new bool[noVertices];
        }
        for (int i = 0; i < noVertices; i++) {
            edge[i][i] = false;
            for (int j = i + 1; j < noVertices; j++) {
                edge[i][j] = (rand() % 1000) < 500;
                edge[j][i] = edge[i][j];
                noEdges += edge[i][j];
            }
        }
    }
    void printEdge() {
        for (int i = 0; i < noVertices; i++) {
            for (int j = 0; j < noVertices; j++) {
                cout << edge[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printGraphToFile(char * oFile) {
        ofstream file;
        file.open(oFile);
        file << noVertices << " " << noEdges << endl;
        for (int i = 0; i < noVertices - 1; i++) {
            for (int j = i + 1; j < noVertices; j++) {
                if (edge[i][j]) {
                    file << i << " " << j << endl;
                }
            }
        }
    }
    
    void BFStravesal(int v) {
    	queue<int> q;
    	q.push(v);
    	bool *visited = new bool[noVertices];
		memset(visited, false, sizeof(visited));
    	visited[v] = true;
    	cout << v << " ";
    	while (!q.empty()) {
    		int w = q.front();
    		q.pop();
    		for (int i = 0; i < noVertices; i++) {
    			if (!visited[i] && edge[w][i]) {
    				visited[i] = true;
    				cout << i << " ";
    				q.push(i);
				}
			}
		}
//		for (int i = 0; i < noVertices; i++) {
//			if (!visited[i]) {
//				cout << endl;
//				BFStravesal(i);
//			}
//		}
	}
	
	void DFStravesal(int v, vector<bool>& visited){
		visited[v] = true;
		cout << v << " ";
		for (int i = v; i <= noVertices; i++) {
			if (!visited[i] && edge[v][i]) {
				DFStravesal(i, visited);
			}
		}
	}
	
	/*
	void constructed(int N) {
		noVertices = N;
        noEdges = 0;
        edge = new bool * [noVertices];
        for (int i = 0; i < noVertices; i++) {
            edge[i] = new bool[noVertices];
        }
        for (int i = 0; i < noVertices; i++) {
            edge[i][i] = false;
            for (int j = i + 1; j < noVertices; j++) {
                int x;
                cin >> x;
                edge[i][j] = x;
                edge[j][i] = edge[i][j];
                noEdges += edge[i][j];
            }
        }
	}
	*/
private:
    bool ** edge;
    int noVertices;
    int noEdges;
};


// Chuong trinh chinh
int main() {
	srand(time(NULL));
    Graph g;
    g.randomGenerate(5);
    //g.constructed(5);
    g.printEdge();
    g.printGraphToFile("ThucHanh14_DoThi_Input.txt");
    g.BFStravesal(0);
    cout << endl;
    vector<bool> visited(5, false);
    g.DFStravesal(0,visited);
    return 0;
}

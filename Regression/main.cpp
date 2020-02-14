#include <list>
#include <vector>
#include <iostream>

// Question 1: implémentation de l’interface à l’aide d’une classe abstraite
class IGraph{
	protected:
	IGraph(){}//constructeur
	~IGraph(){}//destructeur
//methodes virtuelles pure de l'interface	
	public :
	virtual int nbNodes() const =0 ;// nbre de sommet
	virtual int nbEdges() const =0;//nbre d'arêtes
	virtual int degree(int i) const =0;//nbre d'arêtes connectant le sommet i
	virtual std::vector<int> adjacency(int i) const =0;

};

// Question 2:la class graph
class Graph : public IGraph{
	public:
	std::vector<std::vector<int>> graph;	
	public:	
	Graph(std::vector<std::vector<int>> graph){
		this->graph=graph;
		}	
	~Graph(){}
//methode addedge
	void addEdge(int i , int j)
	{

		graph[i].push_back(j);
	}	
	int nbNodes () const 
	{
	 	return graph.size(); 
	}

	int nbEdges() const 
	{
			int cpt=0;
				for(int i=0 ; i<graph.size(); i++)
				{
					cpt+=graph[i].size();
				}  
		return cpt/2 ;
	}	

	int degree (int i) const
	{

		return graph[i].size() ;
	}


	std::vector<int> adjacency (int i)const 
	{

		return graph[i];
	}
	void afficheGraph() const 
	{
		std::cout<<"\nle graphe \n" ;
		for(int i=0 ; i<graph.size(); i++)
		{
			std::cout<<"\nle sommet : \t"<< i  <<"\test connecte a \t";
			for(int j=0;j<graph[i].size() ; j++ )
			{
				std::cout<<graph[i][j] <<"\t" ;
			}
			
		}
		std::cout<<"\n";
	}
	

};
//Question 3:interface IGraphColoring
class IGraphColoring {
	protected:
		IGraphColoring(){} //constructeur
		~IGraphColoring(){}//destructeur	

	public :		
		virtual void coloring (IGraph& g)  =0;
};	
//Question 4:classe GraphColoring
class Gloutonne: public IGraphColoring {
	public :
	Gloutonne(){};//constructeur
	~Gloutonne(){};//destructeur

	void coloring (IGraph& g){

		//Algorithme gloutonne
		auto nbNodes=g.nbNodes(); 
		colors.resize(nbNodes); 
		liste={1};

        for (auto node = 0; node < nbNodes; ++node)     //parcourir les noeuds
        {
            bool color_use = false;     

            //parcourir la liste des couleurs pour eviter de tomber sur la mm couleur (2 noeuds adjacents ne doivent pas avoir la mm couleur
            for (int color : liste)
            {
                bool paint = true;
                for (auto adjacency : g.adjacency(node))
                {
                    
                    if (color == colors[adjacency])
                    {
                        paint = false;
                        if (color == liste.size()) color_use = true;                           
                       break;
                    }
                }

                
                if (paint)
                {
                    colors[node] = color;
                    break;
                }
            }

            if (color_use)
            {
                int new_color = liste.size() + 1;
                liste.push_back(new_color);
                colors[node] = new_color;   //colorier avecla nouvelle couleur ajoutée
            }
        }	

	std::cout<<"\n les couleurs des noeuds du graph sont \n" ;
	for (auto i = 0; i < colors.size(); ++i)
	{
		std::cout<<"\t"<<colors[i] ; 
	}

}
	private:
	std::vector<int> colors,liste;	
		
};

//fonction main
int main(){

	int nb_noeud=7;//nbre du noeud de mon graph
	auto graph_final = std::vector<std::vector<int>>(nb_noeud);
	auto f_graph= Graph(graph_final);
//dans cet exemple j'ai utilisé le graph donné dans l'énnoncé du TD et j'ai seulement ajouté un noeud 0  connecté au noeud 1.
	f_graph.addEdge(0,1);
	
	f_graph.addEdge(1,0);
	f_graph.addEdge(1,2);
	f_graph.addEdge(1,5);
	

	f_graph.addEdge(2,1);
	f_graph.addEdge(2,3);
	f_graph.addEdge(2,5);

	f_graph.addEdge(3,2);
	f_graph.addEdge(3,4);


	f_graph.addEdge(4,3);
	f_graph.addEdge(4,5);
	f_graph.addEdge(4,6);
	

	f_graph.addEdge(5,1);
	f_graph.addEdge(5,2);
	f_graph.addEdge(5,4);
	

	f_graph.addEdge(6,4);
	
	std::cout<<"le nombre de sommet est : "<< f_graph.nbNodes()<<"\n";
	std::cout<<"le nombre d'arêtes est : "<< f_graph.nbEdges()<<"\n";
	f_graph.afficheGraph();

	
	auto glou= new Gloutonne();
	glou->coloring(f_graph);

	return 0;
}

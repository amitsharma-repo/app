#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Vertex
{
    public: 
        Vertex(int p_Value)
        {
           m_Value = p_Value; 
           m_bVisted = false;
        }
        bool addNebiuour(const Vertex* p_Vertex)
        {
            auto l_Itr = std::find(m_Neibours.begin(), m_Neibours.end(), p_Vertex);
            if( m_Neibours.end() != l_Itr )
            {
                std::cout<<"Already exist" <<std::endl;
                return false;
            }
            m_Neibours.push_back(p_Vertex);
            return true;
        }

        int getValue() const
        {
            return m_Value;
        }
        
        void printNeibours()
        {
            for( int i=0; i< m_Neibours.size(); i++)
            {
                std::cout<<m_Neibours[i]->getValue()<<"---";
            }
        }

    private:
        int m_Value;
        bool m_bVisted = false;
        std::vector<const Vertex*> m_Neibours;
};

class Graph
{
    public:
        bool addEdge(int p_From, int p_To)
        {
            Vertex* l_From = getVertexWithVauleIfNotFoundAddNew(p_From);
            Vertex* l_To = getVertexWithVauleIfNotFoundAddNew(p_To);
            l_From->addNebiuour(l_To);
            l_To->addNebiuour(l_From);
            return false;
        }
        void printGraph()
        {
            for(int i=0; i<m_Vertices.size(); i++)
            {
                std::cout<<"V :"<<m_Vertices[i]->getValue() << " ::->";
                m_Vertices[i]->printNeibours();
                std::cout<<std::endl;
            }
        }
        std::vector<int> doBFT(int p_iStartIdx)
        {
            std::vector<int> l_vecBFTSeq;
            Vertex* l_Vertex = getVertexWithVaule(p_iStartIdx);
            if( nullptr == l_Vertex) 
            {
                return l_vecBFTSeq;
            }
            std::queu

            return l_vecBFTSeq;
        }
        void doDFS()
        {
        }
    private: 
        Vertex* addVertex(int p_Value)
        {
            Vertex* l_NewVertex = new Vertex(p_Value);
            m_Vertices.push_back(l_NewVertex);
            return l_NewVertex;
        }

        Vertex* getVertexWithVauleIfNotFoundAddNew(int p_Value)
        {
            Vertex* l_Vertex = getVertexWithVaule(p_Value);
            if ( nullptr == l_Vertex )
            {
               return addVertex(p_Value);
            }
            return l_Vertex;
        }

        Vertex* getVertexWithVaule(int p_Value)
        {
            int i = 0;
            for(i=0; i<m_Vertices.size(); i++)
            {
                if( m_Vertices[i]->getValue() == p_Value)
                {
                    return m_Vertices[i];
                }
            }
            return nullptr;
        }

        std::vector<Vertex*> m_Vertices;
};
int main()
{
    Graph l_Grph; 
    l_Grph.addEdge( 0, 1);
    l_Grph.addEdge( 0, 1);
    l_Grph.addEdge( 0, 4); 
    l_Grph.addEdge( 1, 2); 
    l_Grph.addEdge( 1, 3); 
    l_Grph.addEdge( 1, 4); 
    l_Grph.addEdge( 2, 3); 
    l_Grph.addEdge( 3, 4); 
    l_Grph.printGraph();
    return 0;
}
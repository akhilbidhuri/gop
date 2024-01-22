package main

import (
	"fmt"
)

type Graph struct {
	NumOfNodes int
	AdjList    map[int][]int
	Indegree   []int
}

func (g *Graph) AddNode(id int) {
	if g.AdjList == nil {
		g.AdjList = make(map[int][]int)
	}

	if _, exists := g.AdjList[id]; !exists {
		g.AdjList[id] = []int{}
	}
}

func (g *Graph) AddEdge(source, destination int) {
	if _, exists := g.AdjList[source]; !exists {
		g.AddNode(source)
	}
	g.AdjList[source] = append(g.AdjList[source], destination)
	g.Indegree[destination] += 1
}

func (g Graph) findCouseOrder() []int {
	var nodeToVisit []int
	var courseOrder []int
	indegree := make([]int, g.NumOfNodes)
	copy(indegree, g.Indegree)
	for i := 0; i < g.NumOfNodes; i++ {
		if indegree[i] == 0 {
			nodeToVisit = append(nodeToVisit, i)
		}
	}
	fmt.Println()

	for len(nodeToVisit) > 0 {
		node := nodeToVisit[0]
		nodeToVisit = nodeToVisit[1:]
		if _, exists := g.AdjList[node]; exists {
			for _, adjNode := range g.AdjList[node] {
				indegree[adjNode] -= 1
				if indegree[adjNode] == 0 {
					nodeToVisit = append(nodeToVisit, adjNode)
				}
			}
		}
		courseOrder = append(courseOrder, node)
	}

	if len(courseOrder) == g.NumOfNodes {
		return courseOrder
	}
	return []int{0}
}

func main() {
	var numOfNodes int
	fmt.Println("enter the number of nodes:")
	fmt.Scanf("%d\n", &numOfNodes)

	graph := Graph{NumOfNodes: numOfNodes}

	graph.Indegree = make([]int, numOfNodes)

	fmt.Println("enter the dependencies:")

	for {
		var destination, source int
		fmt.Println("Enter course and prerequisite course:")
		fmt.Scan(&destination, &source)
		graph.AddEdge(source, destination)
		fmt.Println("Dpendencies done?(Y/N):")
		var choice string
		fmt.Scan(&choice)
		if choice == "Y" || choice == "y" {
			break
		}
	}

	courseOrder := graph.findCouseOrder()
	fmt.Println("Course order:")
	for _, node := range courseOrder {
		fmt.Printf("%d ,", node)
	}
	fmt.Println()
}

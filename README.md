# Strip-Tree

The extraction of characteristics from a given geographic source and the way it can be represented in a simple way, while maintaining certain relevant information, known as cartographic generalization. The use of curves to represent different structures is an important part in different areas of research, for example, the representation of highways, rivers, lakes, country borders or even cities and among other representations. Therefore, the representation of these curves is extremely important.

The Strip-tree algorithm presents a methodology to solve this problem.

### Ways of usage

###### --- If you want to read just one file
```
vector<Node*> input = utils.readFile("./data/F1_resolucion_5.txt");
```

###### --- If you want to insert a vector of Node*
```
for(int i=0; i< input.size(); i++){
	t.insert(input[i]);
}
```

###### --- If you want to read several file just varying the resolution
```
stringstream ss;
ss << "./data/F2_" << resolution << ".txt";
vector<Node*> input = utils.readFile(ss.str());
```

###### --- If you want to insert your nodes manually
```
Node* root = new Node(3,7,20,7,5,3);
Node* rl = new Node(3,7,9,12,0,0);
Node* rr = new Node(9,12,20,7,0,4);
Node* rrl = new Node(9,12,15,4,0,0);
Node* rrr = new Node(15,4,20,7,0,0.6);
Node* rrrl = new Node(15,4,18,5,0,0);
Node* rrrr = new Node(18,5,20,7,0,0.6);

t.insert(root);
t.insert(rl);
t.insert(rr);
t.insert(rrl);
t.insert(rrr);
t.insert(rrrl);
t.insert(rrrr);
```

###### --- Display elements with resolution indicated early
```
cout << "[" << endl;
t.displayWithResolution(t.getRoot(),resolution);
cout << "]" << endl;
```

###### --- Calculate the area of strip tree
```
cout << "Area of striptree: " << t.area(t.getRoot()) << endl;
```

###### --- See if strip tree intersect itself.
```
 Point * p = t.intersection(root, rr);
 cout << "Intersect itself in: (" << p->getX() << "," << p->getY() <<")" << endl;
```

###### --- See the smallest rectangle inside the striptree
```
cout << "Smallest Distance:" << t.calcDistance(t.smallestReactangle()) << std::endl;
```

###### --- Calculate the length of the curve
```
cout << "Length: " << t.length(t.getRoot()) << std::endl;
```
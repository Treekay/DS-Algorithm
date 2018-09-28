void bfs(int v) {
  visited[v] = true;
  cout << v << " ";
  queue<int> myque;
  myque.push(v);
  while (!myque.empty()) {
    v = myque.front();
    myque.pop();
    for (list<int>::iterator iter = graph[v].begin(); iter != graph[v].end(); iter++) {
      if (!visited[*iter]) {
        cout << *iter << " ";
        myque.push(*iter);
        visited[*iter] = true;
      }
    }
  }
}
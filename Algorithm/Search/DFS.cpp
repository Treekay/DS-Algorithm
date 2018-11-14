void dfs(int v) { // recursion version
  visited[v] = true;
  cout << v << " ";
  for (list<int>::iterator iter = graph[v].begin(); iter != graph[v].end(); iter++) {
    if (!visited[*iter]) {
      dfs(*iter);
    }
  }
}
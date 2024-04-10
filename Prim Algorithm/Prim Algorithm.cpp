private static int prim(int[][] g) {
	int n = g.length;                               // 图中顶点的个数。
	boolean[] visited = new boolean[n];             // 没被选择的点到集合S的距离。
	int[] dis = new int[n];
	int max = 100;                                  // 默认最大值。    
	Arrays.fill(dis, max);                          // 刚开始的时候距离都默认最大值。     
	visited[0] = true;                              // 选取顶点0作为起始点。   
	for(int i = 0;i < n;i++)
		dis[i] = g[0][i];                           // 更新0到其他点的距离。
	int sum = 0;                                    // 最小生成树的总的权值。

	// 继续查找 n-1 次。
	for(int i = 1;i < n;i++) {
		int v = -1;                                  // 查找集合T中距离S的最小顶点v。
		int minDis = max;                            // 记录顶点v的值。
		for(int j = 0;j < n;j++) {                  // 查找。
			if (!visited[j] && (dis[j] < minDis)) {
				minDis = dis[j];
				v = j;
			}
		}
		System.out.print(v + ",");                   // 打印选择的点。
		visited[v] = true;                          // 把v加到集合S中，表示已经被选择了。
		sum += dis[v];                               // 累加总权值。
		for(int j = 0;j < n;j++) {                   // 更新集合T中和v邻接的顶点。
			if (!visited[j] && g[v][j] < dis[j])
				dis[j] = g[v][j];
		}
	}
	return sum;
}

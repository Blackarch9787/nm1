from collections import deque
def bfs(graph, start, goal):
queue, visited = deque([(start, [start])]), set()
while queue:
node, path = queue.popleft()
if node == goal:
return path
for neighbor in graph[node]:
if neighbor not in visited:
visited.add(neighbor)
queue.append((neighbor, path + [neighbor]))
def visualize_graph(graph, bfs_path):
output = ""
for node in graph:
# Mark nodes in BFS path with an asterisk
if node in bfs_path:
output += node + "*"
else:
output += node
output += " -- " + " -- ".join(graph[node]) + "\n"
return output
graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'],
'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']}
start_node, goal_node = 'A', 'F'
bfs_path = bfs(graph, start_node, goal_node)
# Print graph-based output
print(visualize_graph(graph, bfs_path))

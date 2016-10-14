public class LRUCache {
	private readonly Dictionary<int, LRUNode> NodeMap;
	private readonly int MaxNodeCount;
	private LRUNode Head;
	private LRUNode Tail;
	private int NodeCount;
	
	private class LRUNode {
		public LRUNode Prev {get; set;}
		public LRUNode Next {get; set;}
		public int Key {get; set;}
		public int Value {get; set;}
	}
	
    public LRUCache(int capacity) {
        this.Head = this.Tail = new LRUNode();
		this.NodeCount = 0;
		this.MaxNodeCount = capacity;
		this.NodeMap = new Dictionary<int, LRUNode>();
    }

    public int Get(int key) {
		LRUNode valueNode;
		if (!this.NodeMap.TryGetValue(key, out valueNode)) {
			return -1;
		}
		
		this.MoveToTail(valueNode);		
		return valueNode.Value;
    }

    public void Set(int key, int value) {
        LRUNode valueNode;
		if (this.NodeMap.TryGetValue(key, out valueNode)) {
			valueNode.Value = value;
			this.MoveToTail(valueNode);
			return;
		}
		
		LRUNode newNode = new LRUNode { Key = key, Value = value};
		if (this.NodeCount == this.MaxNodeCount) {
			DeleteLatestUnusedNode();
		}
		
		this.AddNewUnexistNode(newNode);
    }
	
	private void MoveToTail(LRUNode valueNode) {
		// if it is not the latest
		if (valueNode != this.Tail) {
			valueNode.Prev.Next = valueNode.Next;
			valueNode.Next.Prev = valueNode.Prev;
			valueNode.Next = null;
			valueNode.Prev = this.Tail;
			this.Tail.Next = valueNode;
			this.Tail = valueNode;
		}
	}
	
	private void DeleteLatestUnusedNode() {
		if (this.Tail != this.Head) {
			this.Head = this.Head.Next;
			this.NodeMap.Remove(this.Head.Key);
			this.Head.Prev = null;
			this.NodeCount --;
		}
	}

	private void AddNewUnexistNode(LRUNode newNode) {
		this.NodeMap.Add(newNode.Key, newNode);
		this.Tail.Next = newNode;
		newNode.Prev = this.Tail;
		this.Tail = newNode;
		this.NodeCount ++;
	}
}

/**
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently unused item before inserting a new item.
1,[set(2,1),get(2),set(3,2),get(2),get(3)]
Output:
[1,1,2]
Expected:
[1,-1,2]
**/
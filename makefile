all: tree list queue stack

tree: TreeDriver.exe
TreeDriver.exe:
	gcc -o TreeDriver.exe binary-tree/TreeDriver.c binary-tree/tree.c

list: ListDriver.exe
ListDriver.exe:
	gcc -o ListDriver.exe linked-list/ListDriver.c linked-list/list.c

queue: QueueDriver.exe
QueueDriver.exe:
	gcc -o QueueDriver.exe queue/QueueDriver.c queue/queue.c

stack: StackDriver.exe
StackDriver.exe:
	gcc -o StackDriver.exe stack/StackDriver.c stack/stack.c

clean:
	rm -rf *.exe
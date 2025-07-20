/**
1948. Delete Duplicate Folders in System
    Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
    For example, ["one", "two", "three"] represents the path "/one/two/three".
    Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
    For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
    /a
    /a/x
    /a/x/y
    /a/z
    /b
    /b/x
    /b/x/y
    /b/z
    However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
    Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
    Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.

    Example 1:

    Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
    Output: [["d"],["d","a"]]
    Explanation: The file structure is as shown.
    Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
    folder named "b".
 */



function deleteDuplicateFolder(paths: string[][]): string[][] {
        class Node {
        name: string;
        children: Map<string, Node>;
        signature: string;

        constructor(name: string) {
            this.name = name;
            this.children = new Map();
            this.signature = "";
        }
    }

    const root = new Node("");


    for (const path of paths) {
        let node = root;
        for (const folder of path) {
            if (!node.children.has(folder)) {
                node.children.set(folder, new Node(folder));
            }
            node = node.children.get(folder)!;
        }
    }

    const count: Map<string, number> = new Map();

    function DFS1(node: Node): string {
        if (node.children.size === 0) {
            node.signature = "";
            return "";
        }

        const childSignatures: string[] = [];
        const sortedChildren = Array.from(node.children.entries()).sort(([a], [b]) => a.localeCompare(b));
        for (const [name, child] of sortedChildren) {
            const sig = DFS1(child);
            childSignatures.push(`${name}(${sig})`);
        }

        node.signature = childSignatures.join("");
        count.set(node.signature, (count.get(node.signature) || 0) + 1);
        return node.signature;
    }

    DFS1(root);

    const res: string[][] = [];
    const pathStack: string[] = [];

    function DFS2(node: Node) {
        if (node.signature && count.get(node.signature)! > 1) {
            return;
        }

        if (node.name) {
            pathStack.push(node.name);
            res.push([...pathStack]);
        }

        const sortedChildren = Array.from(node.children.values()).sort((a, b) => a.name.localeCompare(b.name));
        for (const child of sortedChildren) {
            DFS2(child);
        }

        if (node.name) {
            pathStack.pop();
        }
    }

    for (const child of Array.from(root.children.values()).sort((a, b) => a.name.localeCompare(b.name))) {
        DFS2(child);
    }

    return res;
};
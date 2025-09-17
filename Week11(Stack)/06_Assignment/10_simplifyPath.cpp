/* -> 71

Given an absolute path for a Unix-style file system, which begins with a slash '/', transform this path into its simplified canonical path.

In Unix-style file system context, a single period '.' signifies the current directory, a double period ".." denotes moving up one directory level, and multiple slashes such as "//" are interpreted as a single slash. In this problem, treat sequences of periods not covered by the previous rules (like "...") as valid names for files or directories.

The simplified canonical path should adhere to the following rules:
    - It must start with a single slash '/'.
    - Directories within the path should be separated by only one slash '/'.
    - It should not end with a slash '/', unless it's the root directory.
    - It should exclude any single or double periods used to denote current or parent directories.

Return the new path.

 

Example 1:
Input: path = "/home/"
Output: "/home"
Explanation: The trailing slash should be removed.

 
Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: Multiple consecutive slashes are replaced by a single one.

Example 3:
Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation: A double period ".." refers to the directory up a level.

Example 4:
Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is not possible.

Example 5:
Input: path = "/.../a/../b/c/../d/./"
Output: "/.../b/d"
Explanation: "..." is a valid name for a directory in this problem.

*/

/*
Appraoch: two pointer + stack 
    -- pehle '/' se lekar dusre '/'(excluding) tak ek part of string manengen, aur push krengen stack m.

    -- start=0, end=start+1;
        Ex: string s = "/a//b////c/d//././/."
            1. /a   -> push on stack
            2. /    -> ignore (no push)
            3. /b   -> push on stack
            4. ///  -> ignore (no push)
            5. /c   -> push on stack
            6. /d   -> push on stack
            7. /    -> ignore (no push)
            8. /.   -> no push
            9. /.   -> no push
            10. /   -> ignore (no push)
            11. /.. -> pop

    -- stack se pop kerke phir reverse 
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void buildAns(stack<string>&s, string &ans)
{
    // base case
    if(s.empty()){
        return;
    }

    string minPath = s.top();
    s.pop();

    //RE
    buildAns(s, ans);
    
    ans += minPath;
}


string simplifyPath(string path)
{
    stack<string> s;

    int i=0;
    while(i<path.size())
    {
        int start = i;
        int end = i+1;

        // next '/' tak
        while (end<path.size() && path[end] != '/')
        {
            ++end;
        }


        string minPath = path.substr(start, end-start);
        i = end;

        if(minPath == "/" || minPath == "/."){
            continue;
        }

        if(minPath != "/.."){
            s.push(minPath);
        }
        else if(!s.empty()){
            s.pop();
        }
        
    }

    string ans = s.empty() ? "/" : "";

    buildAns(s, ans);

    return ans;
}


int main()
{
    string s = "/home//foo/";

    string ans = simplifyPath(s);

    cout << ans << endl;

    return 0;
}
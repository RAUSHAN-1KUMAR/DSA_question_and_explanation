
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
Solved by me
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
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void formingAnser(stack<string> &st, string &ans)
{
    if(st.empty()) return;
    string temp = st.top();
    st.pop();
    formingAnser(st, ans);
    ans += temp;
}

string simplifyPath(string path)
{
    stack<string> st;

    string forst = "";

    for(char ch:path)
    {
        if(ch=='/')
        {
            if(forst.empty())
            {
                forst.push_back(ch);
            }
            else
            {
                if(forst.back() != '/')
                {
                    if(forst == "/."){}//-> neither push nor pull
                    else if(forst=="/..")
                    {
                        // ek directory piche jao
                        if(!st.empty()) st.pop();
                    }
                    else{
                        // aur ager uper ke do nhi h to jo bhi h push hoga
                        st.push(forst);
                    }
                    forst = "/";
                }
            }
        }
        else if(ch=='.')
        {
            forst.push_back(ch);
        }
        else
            forst.push_back(ch);

    }

    //last string 
    if(forst=="/..") if(!st.empty()) st.pop();
    else if(forst=="/."){}
    else if(forst=="/"){}
    else st.push(forst);

    // Last m ager stack khali h to ek home directory to always hoga hi issliye push("/")
    if(st.empty()) st.push("/");

    // forming ans
    string ans="";
    formingAnser(st, ans);

    return ans;
}

int main()
{
    string s = "/.../a/../b/c/../d/./";

    string ans = simplifyPath(s);

    cout << ans << endl;

    return 0;
}
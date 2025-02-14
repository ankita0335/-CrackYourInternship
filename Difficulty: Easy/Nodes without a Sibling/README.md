<h2><a href="https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1">Nodes without a Sibling</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Tree, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in <strong>sorted order </strong>(Increasing). </span><span style="font-size: 18px;">Two nodes are said to be <strong>siblings </strong>if they are present at the same level, and their parents are the same.</span></p>
<p><span style="font-size: 18px;">Note: The root node can not have a sibling so it cannot be included in our answer. If there are no nodes that do not have a sibling then add-1 in the list.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root[] = [37, 20, N, 113]
       37
      /   
    20
    /     
  113 </span>

<span style="font-size: 18px;"><strong>Output: [</strong></span><span style="font-size: 18px;">20, 113]
<strong>Explanation: </strong>Nodes 20 and 113 dont have any siblings.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root[] = [1, 2, 3, 4]
       1
      / \
     2   3<br>    /<br></span>     <span style="font-size: 14pt;">4</span>

<span style="font-size: 18px;"><strong>Output:</strong> [4]
<strong>Explanation: </strong>Node 4 does not have a sibling.<br></span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root[] = [37, 40, N, 13]
       37
      /   
    40
    /     
  13 </span>

<span style="font-size: 18px;"><strong>Output: </strong>[4</span><span style="font-size: 18px;">0, 13]
<strong>Explanation: </strong>Nodes 40 and 13 dont have any siblings.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ number of nodes ≤ 10<sup>4<br></sup>1 ≤ node-&gt;data ≤ 10<sup>4</sup><sup><br></sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;
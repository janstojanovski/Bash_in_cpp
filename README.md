# Bash_in_cpp
An implementation of bash in c++
# How to use it
Compile the c++ file that you downloaded and than you can run it.<br>
Now you can type thees commands:<ul><b>
<li>help&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to provide you with all commands</li>
<li>exit&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to exit the prompt</li>
<li>echo&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to return an argument</li>
<li>whoami&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to return the users name</li>
<li>var&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to return all of the variables</li>
<li>conf&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to configure the shell</li>
<li>cowsay&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to return an argument in cow style</li>
</b></ul>
<h1><b>Usage of variables</b></h1>
You can use variables by doing this:<br>
<b>(the variable name here)=(the value of the variable)</b><br>
note: You can use a quoted string for the value.<br>
To check if you did this corectly you can type var to get all the variables' name and there value. If you want to use the variable you can use her value by typing:<br>
<b>&dollar;(the variable name here)</b><br>
<h1><b>Examples for variables</b></h1>
&gt;&gt;varex="I like programing"<br><br>
&gt;&gt;var<br>
varex&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;I like programing<br>
&gt;&gt;echo &dollar;varex<br>
I like programing<br>&gt;&gt;

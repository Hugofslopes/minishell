<p align="center">
    <img src="https://www.42porto.com/wp-content/uploads/2024/08/42-Porto-Horizontal.png" alt="Pipex Image" />
</p>
<h1 align="center">Minishell</h1>
<p align="center">
    <img src="https://github.com/user-attachments/assets/51a8952d-56ae-4ca3-8d3c-c2691db63696" alt="Image" />
</p>

## Summary
<b>Minishell</b> is a project from 42 School that aims to replicate the behavior of bash.<br>
In this project, we should handle pipes and redirections (<, <<, >, >>), as well as some built-in commands (echo, export, unset, cd, exit, env, and pwd). The project should manage SIGINT, SIGQUIT, and EOF (Ctrl, Ctrl+C, and Ctrl+D). It should handle expansions and quotes (excluding open quotes) and execute the appropriate executable based on the PATH or if an absolute path is provided. This was the first group project from 42 and was made with 
<a href="https://github.com/LN-Dark" style="display: inline-block; padding: 10px 20px; font-size: 16px; color: white; background-color:rgb(237, 242, 247); text-align: center; text-decoration: none; border-radius: 5px; margin-left: 10px;">Pedro Branco</a>

## Code
<ol>
    <li>Initialize all the variables that the program will need, including creating a duplicated of the environment variables (<b>init_ms( )</b>). If there aren't any environment variables, we initialize the envp variable as empty.</li>
    <li>The next step is to call the functions to handle the signals.</li>
    <li>Our program has a personalized prompt, so we create a string that includes the username and the current working directory (pwd), which will serve as our prompt (<b>get_prompt( )</b>).</li>
    <li>Use <b>readline( )</b> to get the input from the user</li>
    <li>Call <b>add_history( )</b> to save the inputs from the user and provide the ability to use the arrow keys to scroll through previously entered inputs.</li>
    <li>Call <b>handle_input( )</b> to check for any pipes and save each one of them in a linked list.</li>
    <li>Call <b>process_pipes( )</b> to execute each one of the pipes</li>
    <li>Call <b>process_redirects( )</b> to check for redirects (including heredocs) and execute them.</li>
    <li>Call <b>choose_builtin()</b> to determine if the command is one of the implemented built-ins; if not, send it to <b>execve( )</b>.</li>
</ol>
   Almost at every step, we check for errors that are related to the function itself.

## Code Setup   
<b>Step 1:</b> Clone the repository

    git clone https://github.com/Hugofslopes/minishell 

<p>
    <b>Step 2:</b> Open the terminal on the repo folder and write
</p>
    make

<p>
    <b>Step 3:</b> Execute
</p>

    ./minishell

<p>
    <b>Step 4:</b> Tests<br>
    There is an XLS document in the repository that contains some of the most important tests for this project. The project can be run without any environment variables using the command:
</p>

    env -i ./minishell

<details>
    <summary>Other tests (Using tmux)</summary>
    <br>
    <p>The best way I found to test if the behavior is exactly the same as Bash was by using a terminal multiplexer (tmux).</p>
    <ol>
        <li>Open the terminal and type tmux (if you have it installed; otherwise, run apt-get update ; apt-get install tmux).</li>
        <li>Navigate to the root of your project.</li>
        <li>Write bash (to enter bash).</li>
        <li>Press <b>ctrl + b</b> and then <b>%</b> (shift + 5, in my case)</li>
        <li>Execute the minishell (<b>./minishell</b>)</li>
        <li>Press <b>ctrl + b</b> and then : (it will open prompt at the end of your screen)</li>
        <li>Write: <b>setw synchronize-panes on</b></li>
        <li>From now on, everything you write in one pane will be written in the other as well.</li>
    </ol>
</details>

## Improvements
<p>
    Improve the parsing and the overall program structure by using tokens instead of a single string.
</p>

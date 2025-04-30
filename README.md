<html>
    <p align="center">
        <img src="https://www.42porto.com/wp-content/uploads/2024/08/42-Porto-Horizontal.png" alt="Pipex Image" />
    </p>
    <h1 align="center">Minishell</h1>
    <p align="center">
        <img src="https://github.com/user-attachments/assets/51a8952d-56ae-4ca3-8d3c-c2691db63696" alt="Image" />
    </p>
</html>

## Summary
<html>
    <p>
        <b>Minishell</b>is a project from 42 School that aims to replicate the behavior of bash.<br>
        In this project, we should handle pipes and redirections (<, <<, >, >>), as well as some built-in commands (echo, export, unset, cd, exit, env, and pwd). The project should manage SIGINT, SIGQUIT, and EOF (Ctrl, Ctrl+C, and Ctrl+D). It should handle expansions and quotes (excluding open quotes) and execute the appropriate executable based on the PATH or if an absolute path is provided. This was the first group project from 42 and was made with @lb-dark.
    </p>
</html>

## Code
## Code Setup
<html>
    <p>    
    <b>Step 1:</b> Clone the repository
    </p>
</html>
 
    git clone https://github.com/Hugofslopes/minishell 

<html>
    <p>
    <b>Step 2:</b> Open the terminal on the repo folder and write
    </p>
</html>

    make

<html>
    <p>
    <b>Step 3:</b> Execute
    </p>
</html>

    ./minishell

<html>
    <p>
    <b>Step 4:</b> Tests<br>
    There is an XLS document in the repository that contains some of the most important tests for this project. There are many more that can be created. The project can be run without any environment variables using the command:
    </p>
</html>

    env -i ./minishell

## Improvements
<html>
    <p>
    Improve the parsing and the overall program structure by using tokens instead of a single string.
    </p>
</html>
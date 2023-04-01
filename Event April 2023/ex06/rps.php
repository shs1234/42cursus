<?php
// Define the options for the game
$options = ['rock', 'paper', 'scissors'];

// Get the user's choice from the command line
echo "Choose rock, paper, or scissors: ";
$user_choice = strtolower(trim(fgets(STDIN)));

// Make sure the user's choice is valid
if (!in_array($user_choice, $options)) {
    echo "Invalid choice!\n";
    exit;
}

// Choose a random option for the computer
$computer_choice = $options[rand(0, 2)];

// Determine the outcome of the game and display the result
if ($user_choice == $computer_choice) {
    echo "Tie! Both chose {$user_choice}.\n";
} elseif (
    ($user_choice == 'rock' && $computer_choice == 'scissors') ||
    ($user_choice == 'paper' && $computer_choice == 'rock') ||
    ($user_choice == 'scissors' && $computer_choice == 'paper')
) {
    echo "Congratulations! You won! The computer chose {$computer_choice}.\n";
} else {
    echo "Sorry, you lost. The computer chose {$computer_choice}.\n";
}
?>

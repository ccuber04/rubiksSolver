import { randomScrambleForEvent } from "cubing/scramble";
import { TwistyPlayer } from "cubing/twisty";

const player = new TwistyPlayer({
    puzzle: "3x3x3",
    visualization: "3D",
});

document.getElementById("cube-container").appendChild(player);

document.getElementById("scramble-btn").onclick = async () => {
    console.log("Generating scramble...");
    let scramble_display = document.getElementById("scramble-display"); 
    scramble_display.innerText = "Scramble: ";
    
    const scramble = await randomScrambleForEvent(player.puzzle);
    console.log(scramble.ToString);
    player.experimentalSetupAlg = scramble.ToString();
    scramble_display.innerText += scramble.ToString();
}

document.getElementById("show-solve-btn").onclick = () => {
    console.log("Showing solution...");
    solution_display = document.getElementById("solution-display");
    solution_display.innerText = "Solution: ";

    // TODO: logic for calling python code to find solution
    solution = "R U R' U' F"; // change to extracting solution
    player.alg = solution.ToString();
    solution_display.innerText += solution;
}

const socket = new WebSocket("ws://localhost:8765");

socket.onopen = () => {
    console.log("Connected");
}

socket.onmessage = (event) => {
    console.log("Received message from server", event.data)
}

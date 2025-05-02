let imageIndex1 = 0;
let imageIndex2 = 0;
let imageIndex3 = 0;

const UI_images = [
    "images/progress/UI & Controls/LCD_01.jpeg",
    "images/progress/UI & Controls/LCD_02.jpeg",
    "images/progress/UI & Controls/LCD_03.jpeg",
    "images/progress/UI & Controls/controls_progress.gif",
    "images/progress/UI & Controls/joystick.jpg"
];

const Arm_images = [
    "images/progress/Adjustable Arm/setup.jpeg",
    "images/progress/Adjustable Arm/arm_progress.gif",
    "images/progress/Adjustable Arm/ball_screw_set.png",
    "images/progress/Adjustable Arm/stepper.png"
];

const Wheel_images = [
    "images/progress/Electronic Wheel/Setup.jpg",
    "images/progress/Electronic Wheel/wheel_progress.gif",
    "images/progress/Electronic Wheel/Stepper.png",
    "images/progress/Electronic Wheel/Hub_Motor.png",
    "images/progress/Electronic Wheel/MotorController.png"
];

function changeImageArm() {
    imageIndex1 = (imageIndex1 + 1) % Arm_images.length;
    document.getElementById("Arm_Image").src = Arm_images[imageIndex1];
}
function changeImageWheel() {
    imageIndex2 = (imageIndex2 + 1) % Wheel_images.length;
    document.getElementById("Wheel_Image").src = Wheel_images[imageIndex2];
}
function changeImageUI() {
    imageIndex3 = (imageIndex3 + 1) % UI_images.length;
    document.getElementById("UI_Image").src = UI_images[imageIndex3];
}


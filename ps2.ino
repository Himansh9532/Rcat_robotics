#include <PS2X_lib.h>

PS2X ps2x;

int error = 0;

#define PS2_DAT 13
#define PS2_CMD 12
#define PS2_ATT 11
#define PS2_CLK 10

void setup()
{
  Serial.begin(9600);
  delay(500);

  Serial.println("Starting PS2 Controller...");

  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_ATT, PS2_DAT, true, true);

  if (error == 0)
  {
    Serial.println("PS2 Controller Connected Successfully!");
  }
  else
  {
    Serial.print("PS2 Controller Not Connected! Error: ");
    Serial.println(error);
  }
}

void loop()
{
  ps2x.read_gamepad(false, 0);

  // Joystick Values
  int LX = ps2x.Analog(PSS_LX);
  int LY = ps2x.Analog(PSS_LY);
  int RX = ps2x.Analog(PSS_RX);
  int RY = ps2x.Analog(PSS_RY);

  Serial.print("LX: "); Serial.print(LX);
  Serial.print("  LY: "); Serial.print(LY);
  Serial.print("  RX: "); Serial.print(RX);
  Serial.print("  RY: "); Serial.println(RY);

  // D-PAD Buttons
  if (ps2x.ButtonPressed(PSB_PAD_UP)) Serial.println("Button Pressed: UP");
  if (ps2x.ButtonPressed(PSB_PAD_DOWN)) Serial.println("Button Pressed: DOWN");
  if (ps2x.ButtonPressed(PSB_PAD_LEFT)) Serial.println("Button Pressed: LEFT");
  if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) Serial.println("Button Pressed: RIGHT");

  // Start / Select
  if (ps2x.ButtonPressed(PSB_START)) Serial.println("Button Pressed: START");
  if (ps2x.ButtonPressed(PSB_SELECT)) Serial.println("Button Pressed: SELECT");

  // Triangle, Circle, Cross, Square
  if (ps2x.ButtonPressed(PSB_TRIANGLE)) Serial.println("Button Pressed: TRIANGLE");
  if (ps2x.ButtonPressed(PSB_CIRCLE)) Serial.println("Button Pressed: CIRCLE");
  if (ps2x.ButtonPressed(PSB_CROSS)) Serial.println("Button Pressed: CROSS");
  if (ps2x.ButtonPressed(PSB_SQUARE)) Serial.println("Button Pressed: SQUARE");

  // L1, L2, R1, R2
  if (ps2x.ButtonPressed(PSB_L1)) Serial.println("Button Pressed: L1");
  if (ps2x.ButtonPressed(PSB_L2)) Serial.println("Button Pressed: L2");
  if (ps2x.ButtonPressed(PSB_R1)) Serial.println("Button Pressed: R1");
  if (ps2x.ButtonPressed(PSB_R2)) Serial.println("Button Pressed: R2");

  // Joystick Button (L3 / R3)
  if (ps2x.ButtonPressed(PSB_L3)) Serial.println("Button Pressed: L3");
  if (ps2x.ButtonPressed(PSB_R3)) Serial.println("Button Pressed: R3");

  // Analog Pressure Values (Only if supported)
  Serial.print("Pressure UP: "); Serial.print(ps2x.Analog(PSAB_PAD_UP));
  Serial.print(" DOWN: "); Serial.print(ps2x.Analog(PSAB_PAD_DOWN));
  Serial.print(" LEFT: "); Serial.print(ps2x.Analog(PSAB_PAD_LEFT));
  Serial.print(" RIGHT: "); Serial.println(ps2x.Analog(PSAB_PAD_RIGHT));

  Serial.print("Pressure TRIANGLE: "); Serial.print(ps2x.Analog(PSAB_TRIANGLE));
  Serial.print(" CIRCLE: "); Serial.print(ps2x.Analog(PSAB_CIRCLE));
  Serial.print(" CROSS: "); Serial.print(ps2x.Analog(PSAB_CROSS));
  Serial.print(" SQUARE: "); Serial.println(ps2x.Analog(PSAB_SQUARE));

  Serial.println("----------------------------------");

  delay(200);
}
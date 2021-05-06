#include "MIDIUSB.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int MuxSelectPin[] = {6,5,4}; //6->MSB
int MuxSelectValue[8][3] = {
                              {0,0,0},
                              {0,0,1},
                              {0,1,0},
                              {0,1,1},
                              {1,0,0},
                              {1,0,1},
                              {1,1,0},
                              {1,1,1}
                                       };
                                       
int MuxSw = A5;
int SwValue[8];
int SwValueLast[8];

int MuxKey1 = A2;
int Key1State[] = {1,1,1,1,1,1,1,1};
int Key1StateLast[] = {1,1,1,1,1,1,1,1};
int Key1NoteValue[] = {60,61,62,63,64,65,66,67};

int MuxKey2 = A3;
int Key2State[] = {1,1,1,1,1,1,1,1};
int Key2StateLast[] = {1,1,1,1,1,1,1,1};
int Key2NoteValue[] = {68,69,70,71,72,73,74,75};

int MuxKey3 = A4;
int Key3State[] = {1,1,1,1,1,1,1,1};
int Key3StateLast[] = {1,1,1,1,1,1,1,1};
int Key3NoteValue[] = {76,77,78,79,80,81,82,83};

int Key25NoteValue = 84;

int MuxPad = A0;
int PadState[] = {1,1,1,1,1,1,1,1};
int PadStateLast[] = {1,1,1,1,1,1,1,1};
int PadName[] = {1,2,3,4,5,6,7,8};
int PadMode = 0;
int DrumPad[] = {37,42,59,49,36,38,50,52};
int ChordPad[8][3] = {
                          {52,55,59}, // PAD1 : Em
                          {51,54,59}, // PAD2 : B/D#
                          {52,57,60}, // PAD3 : Am/E
                          {52,55,59}, // PAD4 : Em
                          {55,59,62}, // PAD5 : G
                          {50,54,57}, // PAD6 : D
                          {52,55,59}, // PAD7 : Em
                          {52,55,60}, // PAD8 : C/E
                                                      };
int MuxKnob = A1;
int KnobValue[8];
int KnobValueLast[8];
int KnobCCNumber[] = {10,70,71,1,7,72,73,74};

int TactSw = 13;
int TactSwState = 0;
int TactSwStateLast = 0;

int Page = 0;
int Octave = 0;
int OctaveLast = 0;
int Transport = 0;
int TransportLast = 0;
int KeyMidiCh = 0;
int PadMidiCh = 0;
int KnobMidiCh = 0;

void setup() {
  Serial1.begin(31250);
  
  lcd.begin(16, 2);
  
  for (int i=0; i<=2; i++){
    pinMode(MuxSelectPin[i], OUTPUT);
  }

  pinMode(MuxSw, INPUT);
  pinMode(MuxKey1, INPUT_PULLUP);
  pinMode(MuxKey2, INPUT_PULLUP);
  pinMode(MuxKey3, INPUT_PULLUP);
  pinMode(MuxPad, INPUT_PULLUP);
  pinMode(MuxKnob, INPUT);

  for (int i=0; i<=7; i++){
    for (int j=0; j<=2; j++){
      digitalWrite(MuxSelectPin[j],MuxSelectValue[i][j]);
    }
    SwValue[i] = SwValueLast[i] = map(analogRead(MuxSw),0,1023,0,127);
    KnobValue[i] = KnobValueLast[i] = map(analogRead(MuxKnob),0,1023,0,127);    
  }  

}

void loop() {
    
  switch(Page){
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Octave = ");
      lcd.print(Octave);          
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Transport = ");
      lcd.print(Transport);          
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Pad Mode = ");
      if (PadMode == 0){
        lcd.print("Drum ");
      }
      else if(PadMode == 1){
        lcd.print("Chord");
      }
      break; 
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Key MIDI CH = ");
      lcd.print(KeyMidiCh+1);   
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("Pad MIDI CH = ");
      lcd.print(PadMidiCh+1);
      break;
    case 5:
      lcd.setCursor(0, 0);
      lcd.print("Knob MIDI CH = ");
      lcd.print(KnobMidiCh+1);
      break;          
  }

  for (int i=0; i<=7; i++){
    for (int j=0; j<=2; j++){
      digitalWrite(MuxSelectPin[j],MuxSelectValue[i][j]);
    }
    SwValue[i] = digitalRead(MuxSw);
    
    if (i==5||i==6){
      SwValue[i] = map(analogRead(MuxSw),0,1023,0,127);
    }
    
    if (SwValue[i] != SwValueLast[i]){
      switch(i){
        case 0: // Menu Up (SW1)
          if(SwValue[i] == LOW){
            lcd.clear();
            Page--;
            if(Page == -1){
              Page = 5;
            }
          }
          break;
        case 1: // Menu Down (SW2)
          if(SwValue[i] == LOW){
            lcd.clear();
            Page++;
            if(Page == 6){
              Page = 0;
            }
          }          
          break;
        case 2: // Value Down (SW3)
          switch(Page){
            case 0: // Octave 
              if(SwValue[i] == LOW){               
                Octave--;
                if(Octave == -5){
                  Octave = -4;
                }
                lcd.setCursor(9, 0);
                lcd.print("  ");                        
              }
              break;
            case 1: // Transport 
              if(SwValue[i] == LOW){
                Transport--;
                if(Transport == -13){
                  Transport = -12;
                }
                lcd.setCursor(12, 0);
                lcd.print("   ");                        
              }       
              break;
            case 2: // PadMode
              if(SwValue[i] == LOW){
                PadMode--;
                if(PadMode == -1){
                  PadMode = 0;
                }                      
              }        
              break; 
            case 3: // KeyMidiCh
              if(SwValue[i] == LOW){
                KeyMidiCh--;
                if(KeyMidiCh == -1){
                  KeyMidiCh = 0;
                }
                lcd.setCursor(12, 0);
                lcd.print("  ");                        
              }        
              break;
            case 4: // PadMidiCh
              if(SwValue[i] == LOW){
                PadMidiCh--;
                if(PadMidiCh == -1){
                  PadMidiCh = 0;
                }
                lcd.setCursor(12, 0);
                lcd.print("  ");                        
              }        
              break;
            case 5: // KnobMidiCh
              if(SwValue[i] == LOW){
                KnobMidiCh--;
                if(KnobMidiCh == -1){
                  KnobMidiCh = 0;
                }
                lcd.setCursor(13, 0);
                lcd.print("  ");                        
              }        
              break;                                                                       
          }
          break;
        case 3: // Value Up (SW4)
          switch(Page){
            case 0: // Octave
              if(SwValue[i] == LOW){
                Octave++;
                if(Octave == 4){
                  Octave = 3;
                }
                lcd.setCursor(9, 0);
                lcd.print("  ");                        
              }
              break;
            case 1: // Transport
              if(SwValue[i] == LOW){
                Transport++;
                if(Transport == 13){
                  Transport = 12;
                }
                lcd.setCursor(12, 0);
                lcd.print("   ");                        
              }        
              break;
            case 2: // PadMode
              if(SwValue[i] == LOW){
                PadMode++;
                if(PadMode == 2){
                  PadMode = 1;
                }                      
              }        
              break;  
            case 3: // KeyMidiCh
              if(SwValue[i] == LOW){
                KeyMidiCh++;
                if(KeyMidiCh == 16){
                  KeyMidiCh = 15;
                }
                lcd.setCursor(12, 0);
                lcd.print("  ");                        
              }        
              break;
            case 4: // PadMidiCh
              if(SwValue[i] == LOW){
                PadMidiCh++;
                if(PadMidiCh == 16){
                  PadMidiCh = 15;
                }
                lcd.setCursor(12, 0);
                lcd.print("  ");                        
              }        
              break;  
            case 5: // KnobMidiCh
              if(SwValue[i] == LOW){
                KnobMidiCh++;
                if(KnobMidiCh == 16){
                  KnobMidiCh = 15;
                }
                lcd.setCursor(13, 0);
                lcd.print("  ");                        
              }        
              break;                                        
          }
          break; 
        case 4: // PEDAL                               
          if(SwValue[i] == HIGH){
            lcd.setCursor(0, 1);
            lcd.print("Sustain Pedal On");
            ControlChange(0xB0+KeyMidiCh,0x40,0x7F); 
          }
          else if(SwValue[i] == LOW){
            lcd.setCursor(0, 1);
            lcd.print("                ");
            ControlChange(0xB0+KeyMidiCh,0x40,0x00);
          }         
          break;
        case 5: // JoyStick-X : Pitch Bend
          lcd.setCursor(0, 1);
          lcd.print("Pitch Bend ON   ");
          PitchBend(0xE0+KeyMidiCh,SwValue[i],SwValue[i]);
          if (SwValue[i] == 65){
            lcd.setCursor(0, 1);
            lcd.print("                ");
            PitchBend(0xE0+KeyMidiCh,0x00,0x40);
          } 
          break;
        case 6: // JoyStick-Y : Modulation
          lcd.setCursor(0, 1);
          lcd.print("Modulation ON   ");          
          ControlChange(0xB0+KeyMidiCh,0x01,map(abs(SwValue[i]-62),0,65,0,127));
          if (SwValue[i] == 62){
            lcd.setCursor(0, 1);
            lcd.print("                ");
            ControlChange(0xB0+KeyMidiCh,0x01,0x00);
          }                      
          break;
        case 7: // KEY25 
          if(SwValue[i] == LOW){
            lcd.setCursor(0, 1);
            lcd.print("Note On : ");
            lcd.print(Key25NoteValue+Transport+Octave*12);
            lcd.print("    ");
            NoteOn(0x90+KeyMidiCh, Key25NoteValue+Transport+Octave*12, 0x64);
            TransportLast=Transport;
            OctaveLast=Octave;             
          }
          else if(SwValue[i] == HIGH){
            lcd.setCursor(0, 1);
            lcd.print("                ");
            NoteOn(0x90+KeyMidiCh, Key25NoteValue+TransportLast+OctaveLast*12, 0x00);
          }         
          break;
      }
    SwValueLast[i] = SwValue[i];
    }   
    
    Key1State[i] = digitalRead(MuxKey1);
    if (Key1State[i] != Key1StateLast[i]){
      if(Key1State[i] == LOW){      
        lcd.setCursor(0, 1);
        lcd.print("Note On : ");
        lcd.print(Key1NoteValue[i]+Transport+Octave*12);
        lcd.print("    ");
        NoteOn(0x90+KeyMidiCh, Key1NoteValue[i]+Transport+Octave*12, 0x64);
        TransportLast=Transport;
        OctaveLast=Octave;        
      }
      else if(Key1State[i] == HIGH){
        lcd.setCursor(0, 1);
        lcd.print("                ");
        NoteOn(0x90+KeyMidiCh, Key1NoteValue[i]+TransportLast+OctaveLast*12, 0x00);
      }
    Key1StateLast[i] = Key1State[i];
    }

    Key2State[i] = digitalRead(MuxKey2);
    if (Key2State[i] != Key2StateLast[i]){
      if(Key2State[i] == LOW){
        lcd.setCursor(0, 1);
        lcd.print("Note On : ");
        lcd.print(Key2NoteValue[i]+Transport+Octave*12);
        lcd.print("    ");
        NoteOn(0x90+KeyMidiCh, Key2NoteValue[i]+Transport+Octave*12, 0x64);
        TransportLast=Transport;
        OctaveLast=Octave;              
      }
      else if(Key2State[i] == HIGH){
        lcd.setCursor(0, 1);
        lcd.print("                ");
        NoteOn(0x90+KeyMidiCh, Key2NoteValue[i]+TransportLast+OctaveLast*12, 0x00);
      }
    Key2StateLast[i] = Key2State[i];
    }

    Key3State[i] = digitalRead(MuxKey3);
    if (Key3State[i] != Key3StateLast[i]){
      if(Key3State[i] == LOW){
        lcd.setCursor(0, 1);
        lcd.print("Note On : ");
        lcd.print(Key3NoteValue[i]+Transport+Octave*12);
        lcd.print("    ");
        NoteOn(0x90+KeyMidiCh,Key3NoteValue[i]+Transport+Octave*12, 0x64);
        TransportLast=Transport;
        OctaveLast=Octave;              
      }
      else if(Key3State[i] == HIGH){
        lcd.setCursor(0, 1);
        lcd.print("                ");
        NoteOn(0x90+KeyMidiCh, Key3NoteValue[i]+TransportLast+OctaveLast*12, 0x00);
      }
    Key3StateLast[i] = Key3State[i];
    }

    PadState[i] = digitalRead(MuxPad);
    if (PadState[i] != PadStateLast[i]){
      if(PadState[i] == LOW){
        lcd.setCursor(0, 1);
        lcd.print("Pad On : ");
        lcd.print(PadName[i]);
        lcd.print("      ");
        if (PadMode == 0){
          NoteOn(0x90+PadMidiCh, DrumPad[i], 0x64);    
        }
        else if (PadMode == 1){
          for (int n=0; n<=2; n++){
            NoteOn(0x90+PadMidiCh, ChordPad[i][n], 0x64);
          }           
        }   
      }
      else if(PadState[i] == HIGH){
        lcd.setCursor(0, 1);
        lcd.print("                ");
        if (PadMode == 0){
          NoteOn(0x90+PadMidiCh, DrumPad[i], 0x00);    
        }
        else if (PadMode == 1){
          for (int n=0; n<=2; n++){
            NoteOn(0x90+PadMidiCh, ChordPad[i][n], 0x00);
          }           
        }        
      }
    PadStateLast[i] = PadState[i];
    }
    
    KnobValue[i] = map(analogRead(MuxKnob),0,1023,0,127);  
    if (abs(KnobValue[i] - KnobValueLast[i])>1){      
      lcd.setCursor(0, 1);
      lcd.print("#CC=");
      lcd.print(KnobCCNumber[i]);
      lcd.print("  ");
      lcd.setCursor(9, 1);
      lcd.print("Vol=");
      lcd.print(KnobValue[i]);
      lcd.print("  ");
      ControlChange(0xB0+KnobMidiCh,KnobCCNumber[i],KnobValue[i]);
    KnobValueLast[i] = KnobValue[i];
    }        
  }
  
  TactSwState = digitalRead(TactSw);
  if (TactSwState != TactSwStateLast){
    if(TactSwState == HIGH){
      lcd.setCursor(0, 1);
      lcd.print("Sustain Pedal On");
      ControlChange(0xB0+KeyMidiCh,0x40,0x64); 
    }
    else if(TactSwState == LOW){
      lcd.setCursor(0, 1);
      lcd.print("                ");
      ControlChange(0xB0+KeyMidiCh,0x40,0x00);
    }
    TactSwStateLast = TactSwState;  
  } 

}

void NoteOn(int nn, int kk, int vv) {
  Serial1.write(nn);
  Serial1.write(kk);
  Serial1.write(vv);
  midiEventPacket_t NoteOn = {0x09, 0x90 | nn, kk, vv};
  MidiUSB.sendMIDI(NoteOn);
  MidiUSB.flush();
}

void ControlChange(int nn, int cc, int vv) {
  Serial1.write(nn);
  Serial1.write(cc);
  Serial1.write(vv);
  midiEventPacket_t ControlChange = {0x09, 0xB0 | nn, cc, vv};
  MidiUSB.sendMIDI(ControlChange);
  MidiUSB.flush();
}

void PitchBend(int nn, int bl, int bh) {
  Serial1.write(nn);
  Serial1.write(bl);
  Serial1.write(bh);
  midiEventPacket_t PitchBend = {0x09, 0xE0 | nn, bl, bh};
  MidiUSB.sendMIDI(PitchBend);
  MidiUSB.flush();
}

package com.tec.controlluces;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;


public class ControlLuces extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {

        //Definicion de variables
        final Boolean[] isPressed = {false};
        final Button bL3, bL4, bL5, bL6, bL7;

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_luces);

        //Boton Luz 3
        bL3 = (Button) findViewById(R.id.Luz3);
        bL3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0])
                    bL3.setBackgroundResource(R.drawable.led_red);
                else
                    bL3.setBackgroundResource(R.drawable.led_green);
                isPressed[0] = !isPressed[0];
            }
        });//Close L3.setOnClickListener

        //Boton Luz 4
        bL4 = (Button) findViewById(R.id.Luz4);
        bL4.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0])
                    bL4.setBackgroundResource(R.drawable.led_red);
                else
                    bL4.setBackgroundResource(R.drawable.led_green);
                isPressed[0] = !isPressed[0];
            }
        });//Close L4.setOnClickListener

        //Boton Luz 5
        bL5 = (Button) findViewById(R.id.Luz5);
        bL5.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0])
                    bL5.setBackgroundResource(R.drawable.led_red);
                else
                    bL5.setBackgroundResource(R.drawable.led_green);
                isPressed[0] = !isPressed[0];
            }
        });//Close L5.setOnClickListener

        //Boton Luz 6
        bL6 = (Button) findViewById(R.id.Luz6);
        bL6.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0])
                    bL6.setBackgroundResource(R.drawable.led_red);
                else
                    bL6.setBackgroundResource(R.drawable.led_green);
                isPressed[0] = !isPressed[0];
            }
        });//Close L6.setOnClickListener

        //Boton Luz 7
        bL7 = (Button) findViewById(R.id.Luz7);
        bL7.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0])
                    bL7.setBackgroundResource(R.drawable.led_red);
                else
                    bL7.setBackgroundResource(R.drawable.led_green);
                isPressed[0] = !isPressed[0];
            }
        });//Close L7.setOnClickListener


    }//Close void onCreate


}//End Class

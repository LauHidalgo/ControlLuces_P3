import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import com.tec.controlluces.R;

public class buttons extends AppCompatActivity {

    //Creacion de variables
    Boolean[] isPressed = {false};
    Button bL3, bL4, bL5, bL6, bL7;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_buttons);

        //Boton Luz 3
        bL3 = (Button) findViewById(R.id.Luz3);
        bL3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL3.setBackgroundResource(R.drawable.led_red);}
                else{ //led on
                    bL3.setBackgroundResource(R.drawable.led_green);}
                isPressed[0] = !isPressed[0];}//close onClick
        });//Close L3.setOnClickListener

        //Boton Luz 4
        bL4 = (Button) findViewById(R.id.Luz4);
        bL4.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL4.setBackgroundResource(R.drawable.led_red);}
                else{//led on
                    bL4.setBackgroundResource(R.drawable.led_green);}
                isPressed[0] = !isPressed[0];}//Close onClick
        });//Close L4.setOnClickListener

        //Boton Luz 5
        bL5 = (Button) findViewById(R.id.Luz5);
        bL5.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL5.setBackgroundResource(R.drawable.led_red);}
                else{//led on
                    bL5.setBackgroundResource(R.drawable.led_green);}
                isPressed[0] = !isPressed[0];}//close onClick
        });//Close L5.setOnClickListener

        //Boton Luz 6
        bL6 = (Button) findViewById(R.id.Luz6);
        bL6.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){//led off
                    bL6.setBackgroundResource(R.drawable.led_red);}
                else{//led on
                    bL6.setBackgroundResource(R.drawable.led_green);}
                isPressed[0] = !isPressed[0];}//Close onClick
        });//Close L6.setOnClickListener

        //Boton Luz 7
        bL7 = (Button) findViewById(R.id.Luz7);
        bL7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (isPressed[0]) {//led off
                    bL7.setBackgroundResource(R.drawable.led_red);
                } else { //led on
                    bL7.setBackgroundResource(R.drawable.led_green);
                }
                isPressed[0] = !isPressed[0];
            }//Close onClick
        });//Close L7.setOnClickListener
    }//Close onCreate
}//Close class
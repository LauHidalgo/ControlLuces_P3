package com.tec.lc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class ControlLuces extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Button bL4;

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_luces);

        bL4 = (Button) findViewById(R.id.Luz4);
        bL4.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                Toast.makeText(getBaseContext(),"bubububu4",Toast.LENGTH_LONG).show();
            }
        });
    }

    public void L3OnClick(View v){
        Toast.makeText(getBaseContext(),"bubububu3",Toast.LENGTH_LONG).show();
        }//Close L3OnClick

}//End class

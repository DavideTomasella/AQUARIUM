package org.hopto.raspberryddns.aquarium;

import android.app.Fragment;
import android.content.Context;
import android.net.DhcpInfo;
import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.design.widget.BottomNavigationView;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView mTextMessage;
    private int lastSelectedItemId = 0;
    static protected TypeConnection connessione = TypeConnection.OTHER;

    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            int newItemId = item.getItemId();
            if(newItemId!=R.id.navigation_home || lastSelectedItemId!=newItemId) {
                switch (item.getItemId()) {
                    case R.id.navigation_home:
                        lastSelectedItemId = R.id.navigation_home;
                        createHome();
                        return true;
                    case R.id.navigation_misure:
                        lastSelectedItemId = R.id.navigation_misure;
                        createMisure();
                        return true;
                    case R.id.navigation_errori:
                        lastSelectedItemId = R.id.navigation_errori;
                        createErrori();
                        return true;
                }
            }
            return false;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setTypeConnection();

        BottomNavigationView navigation = (BottomNavigationView) findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);

        createHome();

    }

    private void createHome(){
        FragmentTransaction ft = getSupportFragmentManager().beginTransaction();
        contFragment fragment = new contFragment();
        ft.replace(R.id.content_frame, fragment);
        setTitle("AQUARIUM");
        ft.commit();
    }

    private void createMisure(){
        FragmentTransaction ft = getSupportFragmentManager().beginTransaction();
        misureFragment fragment = new misureFragment();
        ft.replace(R.id.content_frame, fragment);
        setTitle(R.string.title_misure);
        ft.commit();
    }

    private void createErrori(){
        FragmentTransaction ft = getSupportFragmentManager().beginTransaction();
        erroriFragment fragment = new erroriFragment();
        ft.replace(R.id.content_frame, fragment);
        setTitle(R.string.title_errori);
        ft.commit();
    }

    private void setTypeConnection(){
        try {
            WifiManager wifii= (WifiManager) this.getApplicationContext().getSystemService(Context.WIFI_SERVICE);
            DhcpInfo d = wifii.getDhcpInfo(); //return 0 if no wifi connection
            if(d.gateway == 16885952) connessione = TypeConnection.WIFI_HOME; //192.168.1.1 0101a8c0
            else if(d.gateway == 0) connessione = TypeConnection.INTERNET;
            else connessione = TypeConnection.WIFI_SCHOOL;                    //172.16.1.1 (251?)
        }catch (NullPointerException e){
            connessione=TypeConnection.INTERNET;
        }
    }

}

package org.hopto.raspberryddns.aquarium;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;

import com.bumptech.glide.Glide;
import com.bumptech.glide.load.engine.DiskCacheStrategy;

public class contFragment extends Fragment implements View.OnClickListener {

    private Activity context;
    private TypeConnection connection;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        //returning our layout file
        //change R.layout.yourlayoutfilename for each of your fragments

        this.context = super.getActivity();
        this.connection = MainActivity.connessione;

        View v = inflater.inflate(R.layout.fragment_cont, container, false);

        Button b = (Button) v.findViewById(R.id.button);
        b.setOnClickListener(this);

        ImageView imageView = (ImageView) v.findViewById(R.id.imageView);
        //GlideDrawableImageViewTarget imageViewTarget = new GlideDrawableImageViewTarget(imageView);
        Glide.with(this)
                .load(R.drawable.videotogif_7)
                .into(imageView);
                //.diskCacheStrategy(DiskCacheStrategy.NONE)
                //.centerCrop()
                //.crossFade()
                //.into(imageViewTarget);

        return v;
    }

    /*
    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {

        ImageView imageView = (ImageView) view.findViewById(R.id.imageView);
        GlideDrawableImageViewTarget imageViewTarget = new GlideDrawableImageViewTarget(imageView);
        //String filePath = "/storage/emulated/0/Movies/vid2.mp4";
        //Glide.with(this)
        //        .load(Uri.fromFile(new File(filePath)))
        //       .into(imageView);
        Glide.with(this)
                .load(R.drawable.videotogif_7)
                .diskCacheStrategy(DiskCacheStrategy.NONE)
                .centerCrop()
                .crossFade()
                .into(imageViewTarget);
        new SimpleTarget<Bitmap>{

            @Override
            public void onResourceReady(Bitmap resource,GlideAnimation<? extends Bitmap>(){
                // resize the bitmap
                bitmap = resize(width,height);
                imageView.setImageBitmap(bitmap);
            }

        })
        //GifImageView gifImageView = (GifImageView) view.findViewById(R.id.GifImageView);
        //gifImageView.setGifImageResource(R.drawable.videotogif_6);
    }*/
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.button:
                String uri;
                if(connection == TypeConnection.WIFI_SCHOOL) uri = context.getResources().getString(R.string.urlPre1);
                else if(connection == TypeConnection.WIFI_HOME) uri = context.getResources().getString(R.string.urlPre2);
                else uri = context.getResources().getString(R.string.urlPre2);
                Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(uri));
                startActivity(browserIntent);

                break;
        }
    }
}


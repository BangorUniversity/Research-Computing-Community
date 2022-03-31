# Rclone and Microsoft OneDrive

- [Install Rclone on Windows](#install-rclone-on-windows)
- [Install Rclone on Linux/macOS/BSD systems](#install-rclone-on-linuxmacosbsd-systems)
- [Configure Rclone](#configure-rclone)
- [List files on Microsoft OneDrive](#list-files-on-microsoft-onedrive)
- [Upload files to Microsoft OneDrive](#upload-files-to-microsoft-onedrive)
- [Download files from Microsoft OneDrive](#download-files-from-microsoft-onedrive)
- [Sync files with Microsoft OneDrive](#sync-files-with-microsoft-onedrive)
- [Connect SCW to Microsoft OneDrive](#connect-scw-to-microsoft-onedrive)

## About

[Rclone](https://rclone.org/) is a command line program to manage files on cloud storage. It is a feature rich alternative to cloud vendors' web storage interfaces. Over 40 cloud storage products support rclone including S3 object stores, business & consumer file storage services, as well as standard transfer protocols.

## Install Rclone on Windows

- [Download](https://rclone.org/downloads/) the relevant binary.
- Extract the rclone executable, rclone.exe on Windows, from the archive.

## Install Rclone on Linux/macOS/BSD systems

- Install Rclone.

    ```sh
    sudo curl https://rclone.org/install.sh | bash
    ```

- Verify installation was successful.    


    ```sh
    rclone --version
    ```
    
    Example output
    ```
    rclone v1.58.0
    - os/version: darwin 12.1 (64 bit)
    ```
    
## Configure Rclone

- For this tutorial we will connect to Microsoft OneDrive, however a full list of supported providers and configuration details are available under the 'Supported Providers' heading on [Rclone's homepage](https://rclone.org/).

- Create a remote called `bangor`.


    ```sh
    rclone config
    ```


- Create a new remote by typing `n` and press `Enter`.


    ```sh
    n/s/q> n
    ```


- Set the name of the new remote by typing `bangor` and press `Enter`.


    ```sh
    name> bangor
    ```


- Find the id number for 'Microsoft Onedrive' from the list of supported providers, type the id number and press `Enter`.


    ```sh
    28 / Microsoft OneDrive
        \ (onedrive)
    
    Storage> 28
    ```

- Leave Oauth Client Id empty and press `Enter`.


    ```sh
    client_id>
    ```

- Leave Oauth Client Secret empty and press `Enter`.


    ```sh
    client_secret>
    ```

- Find the id number for 'Microsoft Cloud Global' from the list of national cloud regions, type the id number and press `Enter`.

    ```sh
     1 / Microsoft Cloud Global
        \ (global)
   
    region> 1
    ```

- Omit editing the advanced config by typing `n` and press `Enter`.


    ```sh
    y/n> n
    ```

- Select the auto config option by typing `y` and press `Enter`.    


    ```sh
    y/n> y
    ```


- A browser window should open, prompting you to login with your Microsoft OneDrive credentials. Upon a successful login, a 'Success. All Done. Please go back to rclone.' message should be displayed.

- Find the id number for 'OneDrive Personal or Business' from the config type list, type the id number and press `Enter`.


    ```sh
    1 / OneDrive Personal or Business
       \ (onedrive)
   
    config_type> 1
    ```

- Confirm the correct drive has been found by typing `y` and press `Enter`.


    ```sh
    Drive OK?

    Found drive "root" of type "business"
    URL: https://bangoroffice365-my.sharepoint.com/personal/{username}_bangor_ac_uk/Documents

    y/n> y
    ```


- Confirm configuration by typing `y` and press `Enter`.


    ```sh
    y/n> y
    ```


- The `bangor` remote should be listed in the current remotes output.  


    ```sh
    Current remotes:
    
    Name         Type
    ====         ====
    bangor       onedrive
    ```
    
    
- Quit setup by typing `q` and press `Enter`.    


    ```sh
    e/n/d/r/c/s/q> q
    ```
    
## List files on Microsoft OneDrive

- View a list of files on the `bangor` remote.


    ```sh
    rclone ls bangor:
    ```


- View a list of directories on the `bangor` remote.


    ```sh
    rclone lsd bangor:
    ```

## Upload files to Microsoft OneDrive


**Note** Rclone `copy` will copy files from source to destination, skipping already copied.


- Create a `upload_demo` directory.


    ```sh
    mkdir upload_demo
    ```


- Create a test file in the `upload_demo` directory.


    ```sh
    echo "Hello Rclone" > upload_demo/test.txt
    ```


- Copy the `upload_demo` directory to the `bangor` remote.


    ```sh
    rclone copy upload_demo bangor:upload_demo
    ```


- Verify directory and test file has been uploaded.


    ```sh
    rclone cat bangor:upload_demo/test.txt
    ```

## Download files from Microsoft OneDrive


**Note** Rclone `copy` will copy files from source to destination, skipping already copied.


- View a list of directories on the `bangor` remote.


    ```sh
    rclone lsd bangor:
    
    
    >> -1 2021-01-22 14:06:58         1 download_demo
    ```

- Download a folder that exists on the `bangor` remote .


    ```sh
    rclone copy bangor:download_demo download_demo
    ```
    
## Sync files with Microsoft OneDrive

**Note** Rclone `sync` will make the source and destination identical, modifying destination only.

- The difference between copying files and synchronising files is that `copy` creates duplicates from a source to a destination, but `sync` creates a replica of the source at the destination. 
- If files are deleted from the source, synchronising the source and destination will delete files from the destination as well. 
- Copying will never delete files in the destination.

- Create a `sync_demo` directory.


    ```sh
    mkdir sync_demo
    ```


- Create a test file in the `sync_demo` directory.


    ```sh
    echo "Hello Rclone" > sync_demo/test.txt
    ```


- Sync the `sync_demo` directory to the `bangor` remote.


    ```sh
    rclone sync sync_demo bangor:sync_demo
    ```


- Verify directory and test file has been synced.


    ```sh
    rclone cat bangor:sync_demo/test.txt
    ```
    
- Delete the test file in the `sync_demo` directory.

    ```sh
    rm sync_demo/test.txt
    ```
    
- Sync the `sync_demo` directory to the `bangor` remote.

    ```sh
    rclone sync sync_demo bangor:sync_demo
    ```
    
- Verify file has been deleted from the `bangor` remote.

    ```sh
    rclone lsd bangor:sync_demo
    ```
    
## Connect SCW to Microsoft OneDrive

- Rclone stores all its config in a single configuration file. This can easily be copied to SCW to enable access to Microsoft OneDrive.

- First, find the config file by running `rclone config file`.

    ```sh
    $ rclone config file
    
    Configuration file is stored at:
    /home/user/.rclone.conf
    ```
- Transfer it to SCW via scp

    ```sh
    scp /home/user/.rclone.conf username@hawklogin.cf.ac.uk:/home/username/.config/rclone/rclone.conf
    ```
- Login to SCW and test the rclone config by viewing a list of directories in the `bangor` remote.

    ```
    ssh username@hawklogin.cf.ac.uk
    
    rclone lsd bangor:
    ```

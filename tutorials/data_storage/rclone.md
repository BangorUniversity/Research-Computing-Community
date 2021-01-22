## Rclone and OneDrive

- [Setup on Windows](#setup-on-windows)
- [Setup on MacOS and Linux](#setup-on-macos-and-linux)
- [List files on OneDrive](#list-files-on-onedrive)
- [Upload files to OneDrive](#upload-files-to-onedrive)
- [Download files from OneDrive](#download-files-from-onedrive)

---

### About

[Rclone](https://rclone.org/) is a command line program to manage files on cloud storage. It is a feature rich alternative to cloud vendors' web storage interfaces. Over 40 cloud storage products support rclone including S3 object stores, business & consumer file storage services, as well as standard transfer protocols.

---

### Setup on Windows

- TODO

---

### Setup on MacOS and Linux

- Install Rclone.


    ```sh
    sudo curl https://rclone.org/install.sh | bash
    ```


- Verify installation was successful.    


    ```sh
    rclone --version
    ```

 
- For this tutorial we will connect to OneDrive, however a full list of supported providers and configuration details are available under the 'Supported Providers' heading on [Rclone's homepage](https://rclone.org/).

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
    Storage> 23
    ```

- Leave Oauth Client Id empty and press `Enter`.


    ```sh
    client_id>
    ```

- Leave Oauth Client Secret empty and press `Enter`.


    ```sh
    client_secret>
    ```


- Omit editing the advanced config by typing `n` and press `Enter`.


    ```sh
    y/n> n
    ```


- Select the auto config option by typing `y` and press `Enter`.    


    ```sh
    y/n> y
    ```


- A browser window should open, prompting you to login with your OneDrive credentials. Upon a successful login, a 'Success. All Done. Please go back to rclone.' message should be returned.
- Find the id number for 'Root Sharepoint site' from the site list, type the id number and press `Enter`.


    ```sh
    Your choice> 2
    ```


- Find the id number for 'Documents' from the drive list, type the id number and press `Enter` .


    ```sh
    Your choice> 1
    ```


- Confirm selection by typing `y` and press `Enter`.


    ```sh
    y/n> y
    ```


- Confirm configuration by typing `y` and press `Enter`.


    ```sh
    y/n> y
    ```


- The `bangor` remote should be listed in the current remotes output.  


    ```sh
    Current remotes:
    
    Name         Type
    ====         ====
    bangor       onedrive
    ```
    
    
- Quit setup by typing `q` and press `Enter`.    


    ```sh
    e/n/d/r/c/s/q> q
    ```
    
---

### List files on OneDrive

- View a list of files on the `bangor` remote.


    ```sh
    rclone ls bangor:
    ```


- View a list of directories on the `bangor` remote.


    ```sh
    rclone lsd bangor:
    ```

---

### Upload files to OneDrive


**Note** Rclone `copy` will copy files from source to destination, skipping already copied.


- Create a `copy_demo` directory.


    ```sh
    mkdir copy_demo
    ```


- Create a test file in the `copy_demo` directory.


    ```sh
    echo "Hello, Rclone" > copy_demo/hello.txt
    ```


- Copy the `copy_demo` directory to the `bangor` remote.


    ```sh
    rclone copy copy_demo bangor:copy_demo
    ```


- Verify directory and test file has been copied.


    ```sh
    rclone cat bangor:copy_demo/hello.txt
    ```

---

### Download files from OneDrive


**Note** Rclone `copy` will copy files from source to destination, skipping already copied.


- View a list of directories on the `bangor` remote.


    ```sh
    rclone lsd bangor:
    
    
    >> -1 2021-01-22 14:06:58         1 download_demo
    ```

- Download a folder that exists on the `bangor` remote .


    ```sh
    rclone copy bangor:download_demo download_demo
    ```

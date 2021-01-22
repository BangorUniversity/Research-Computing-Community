## Rclone connect to One Drive


- [Windows](#windows)
- [MacOS and Linux](#macos-and-linux)

---

### About

[Rclone](https://rclone.org/) is a command line program to manage files on cloud storage. It is a feature rich alternative to cloud vendors' web storage interfaces. Over 40 cloud storage products support rclone including S3 object stores, business & consumer file storage services, as well as standard transfer protocols.

---

### Windows

- TODO

---

### MacOS and Linux

#### Setup

- Install Rclone.

    ```
    sudo curl https://rclone.org/install.sh | bash
    ```
    
- Verify installation was successful. 

  ```
  rclone --version
  ```
  
For this tutorial we will connect to OneDrive, however a full list of supported providers and configuration details are available under the 'Supported Providers' heading on [Rclone's homepage](https://rclone.org/).

- Create a remote called `bangor`.

  ```
  rclone config
  ```

- Create a new remote by typing `n` and press `Enter`.

  ```
  n/s/q> n
  ```

- Set the name of the new remote by typing `bangor` and press `Enter`.

  ```
  name> bangor
  ```

- Find the id number for 'Microsoft Onedrive' from the list of supported providers, type the id number and press `Enter`.

  ```
  Storage> 23
  ```
  
- Leave Oauth Client Id empty and press `Enter`.

  ```
  client_id>
  ```
  
- Leave Oauth Client Secret empty and press `Enter`.

  ```
  client_secret>
  ```

- Omit editing the advanced config by typing `n` and press `Enter`.

  ```
  y/n> n
  ```
  
- Select the auto config option by typing `y` and press `Enter`.
  
  ```
  y/n> y
  ```

- A browser window should open, prompting you to login with your OneDrive credentials. Upon a successful login, a 'Success. All Done. Please go back to rclone.' message should be returned.

- Find the id number for 'Root Sharepoint site' from the site list, type the id number and press `Enter`.

  ```
  Your choice> 2
  ```
  
- Find the id number for 'Documents' from the drive list, type the id number and press `Enter`.

  ```
  Your choice> 1
  ```
  
- Confirm selection by typing `y` and press `Enter`.

  ```
  y/n> y
  ```
  
- Confirm configuration by typing `y` and press `Enter`.

  ```
  y/n> y
  ```
  
- The `bangor` remote be listed in the current remotes output.


  ```
  Current remotes:
  
  Name         Type
  ====         ====
  bangor       onedrive
  ```

- Quit setup by typing `q` and press `Enter`.
  
  ```
  e/n/d/r/c/s/q> q
  ```
  
#### Usage

#### List files on remote

- View a list of files on `bangor` remote.

  ```
  rclone ls bangor:
  ```
  
- View a list of directories `bangor` remote.

  ```
  rclone lsd bangor:
  ```
  
##### Copy files to remote

**Note** Rclone `copy` will copy files from source to destination, skipping already copied.

###### Upload files to remote

- Create a `copy_demo` directory.

  ```
  mkdir copy_demo
  ```
  
- Create a test file in the `copy_demo` directory.

  ```
  echo "Hello, Rclone" > copy_demo/hello.txt
  ```
  
- Copy the `copy_demo` directory to the `bangor` remote.

  ```
  rclone copy copy_demo bangor:copy_demo
  ```

- Verify directory and test file has been copied.

  ```
  rclone cat bangor:copy_demo/hello.txt
  ```
  
###### Download files from remote
  

- View a list of directories `bangor` remote.

  ```
  rclone lsd bangor:
  ```
  
  Output example
  
  ```
  -1 2021-01-22 14:06:58         1 download_demo
  ```
  
- Download a folder that exists in the `bangor` remote.

  ```
  rclone copy bangor:download_demo download_demo
  ```

  
  
  
  
  

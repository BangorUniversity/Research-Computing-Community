### Generate SSH keys
1. Generate an SSH key that uses the Ed25519 algorithm.

    ```
    ssh-keygen -a 100 -t ed25519 -f ~/.ssh/id_ed25519
    ```

    - `-a` Specifies the number of KDF (key derivation function) rounds used.  Higher numbers result in slower passphrase verification and increased resistance to brute-force password cracking.

    - `-t` Specifies the type of key to create.

    - `-f` Specifies the filename of the key file.

      

    Generated keys:

    - Private `~/.ssh/id_ed25519`
    - Public `~/.ssh/id_ed25519.pub`

    

    A useful command to check all available SSH keys.

    ```
    for key in ~/.ssh/id_*; do ssh-keygen -l -f "${key}"; done | uniq
    ```

    

2. Upload the public key to the remote host.

    ```
    ssh-copy-id -i ~/.ssh/id_ed25519 username@remote-host
    ```

    - `i` Use only the key(s) contained in identity_file.

    

3. Test the public key has been uploaded to the remote host.

    ```
    ssh -i ~/.ssh/id_ed25519 username@remote-host
    ```

    

4. Update the SSH config on the local host.

    ```
    vi ~/.ssh/config
    ```

    ```
    Host remote-host 
      HostName remote-host 
      User username   
      IdentityFile ~/.ssh/id_ed25519
      IdentitiesOnly yes
    ```

    

5. Test SSH configuration.

    ```
    ssh remote-host
    ```



6. Configure filezilla site manager to use key file.

   ![](/Users/tysta/Code/2020/Research-Computing-Community/tutorials/ssh/filezilla.png)



#### Resources

---
- [Ed25519 Algorithm](https://ed25519.cr.yp.to/)
- [Upgrade Your SSH Key to Ed25519](https://medium.com/risan/upgrade-your-ssh-key-to-ed25519-c6e8d60d3c54)
- [ssh-copy-id](https://www.ssh.com/ssh/copy-id)


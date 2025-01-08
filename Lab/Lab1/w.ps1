# Define the name of your Wi-Fi adapter
$wifiAdapter = (Get-NetAdapter | Where-Object { $_.Status -eq "Up" -and $_.InterfaceDescription -like "*Wi-Fi*" }).Name

if (-not $wifiAdapter) {
    Write-Host "No active Wi-Fi adapter found."
    exit
}

# Get the current state of the Wi-Fi adapter
$adapterStatus = Get-NetAdapter -Name $wifiAdapter | Select-Object -ExpandProperty Status

if ($adapterStatus -eq "Up") {
    # Turn off Wi-Fi
    Write-Host "Wi-Fi is currently ON. Turning it OFF..."
    Disable-NetAdapter -Name $wifiAdapter -Confirm:$false
    Write-Host "Wi-Fi is now OFF."
} elseif ($adapterStatus -eq "Disabled") {
    # Turn on Wi-Fi
    Write-Host "Wi-Fi is currently OFF. Turning it ON..."
    Enable-NetAdapter -Name $wifiAdapter -Confirm:$false
    Write-Host "Wi-Fi is now ON."
} else {
    Write-Host "Wi-Fi adapter is in an unknown state: $adapterStatus"
}

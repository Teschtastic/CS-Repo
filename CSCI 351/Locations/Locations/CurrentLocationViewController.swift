//
//  FirstViewController.swift
//  Locations
//
//  Created by Sean Tesch on 10/14/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import CoreLocation

class CurrentLocationViewController: UIViewController, CLLocationManagerDelegate {
    
    let locationManager = CLLocationManager()
    var location: CLLocation?
    
    var geocoder = CLGeocoder()
    var placeMark: CLPlacemark?
    
    @IBOutlet weak var messageLabel: UILabel!
    @IBOutlet weak var latitudeLabel: UILabel!
    @IBOutlet weak var longitudeLabel: UILabel!
    @IBOutlet weak var addressLabel: UILabel!
    @IBOutlet weak var tagButton: UIButton!
    
    
    func showLocationServicesDeniedAlert() {
        let alert = UIAlertController(title: "Location Services Disabled", message: "Please enable location services for this app in Settings.", preferredStyle: .Alert)
        let okAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
        alert.addAction(okAction)
        presentViewController(alert, animated: true, completion: nil)
    }
    
    func updateLabels() {
        if let location = location {
            latitudeLabel.text = String(format: "%.8f", location.coordinate.latitude)
            longitudeLabel.text = String(format: "%.8f", location.coordinate.longitude)
            
            geocoder.reverseGeocodeLocation(location, completionHandler: {
                placemarks, error in
                if error == nil, let p = placemarks
                where !p.isEmpty {
                    self.placeMark = p.last
                    self.addressLabel.text = "\(self.placeMark?.thoroughfare!)\n \(self.placeMark?.postalCode!)\n \(self.placeMark?.locality!)\n \(self.placeMark?.country!)\n"
                }
            })
            
            tagButton.hidden = false
            messageLabel.text = ""
        } else {
            latitudeLabel.text = ""
            longitudeLabel.text = ""
            addressLabel.text = ""
            tagButton.hidden = true
            messageLabel.text = "Tap 'Get My Location' to Start"
        }
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        locationManager.requestAlwaysAuthorization()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBAction func getLocation(sender: AnyObject) {
        
        let authStatus = CLLocationManager.authorizationStatus()
        
        if authStatus == .NotDetermined {
            locationManager.requestWhenInUseAuthorization()
            return
        }
        
        if authStatus == .Denied || authStatus == .Restricted {
            showLocationServicesDeniedAlert()
            return
        }
        
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters
        locationManager.startUpdatingLocation()
    }
    
    
    
    // MARK: - CLLocationManagerDelegate
    func locationManager(manager: CLLocationManager, didFailWithError error: NSError) {
        print("didFailWithError \(error)")
    }
    
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let newLocation = locations.last!
        print("didUpdateLocations \(newLocation)")
        location = newLocation
        updateLabels()
    }
    
    
}


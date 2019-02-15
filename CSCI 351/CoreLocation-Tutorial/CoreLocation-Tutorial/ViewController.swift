//
//  ViewController.swift
//  CoreLocation-Tutorial


import UIKit
import CoreLocation


class ViewController: UIViewController, CLLocationManagerDelegate {
    
    @IBOutlet weak var latitudeLabel: UILabel!
    @IBOutlet weak var longitudeLabel: UILabel!
    @IBOutlet weak var adressLabel: UILabel!
    @IBOutlet weak var button: UIButton!
    
    var manager = CLLocationManager()
    var geocoder = CLGeocoder()
    var placeMark: CLPlacemark?
    
   
    
    override func viewDidLoad() {
        super.viewDidLoad()
        manager.requestAlwaysAuthorization()
    }
    

    
    func locationManager(manager: CLLocationManager, didFailWithError error: NSError) {
        print("ERROR: \(error.localizedDescription)")
        
    }
    
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        print("new Location: \(manager.location)")
        
        let currentLocation = manager.location
        
        if currentLocation != nil {
            latitudeLabel.text = "\(currentLocation!.coordinate.latitude)"
            longitudeLabel.text = "\(currentLocation!.coordinate.longitude)"
            
            geocoder.reverseGeocodeLocation(currentLocation!, completionHandler: {
            placemarks, error in
                var a1 = "", a2="", a3="", a4=""
                if error == nil, let p=placemarks where !p.isEmpty {
                    self.placeMark = p.last!
                    if (self.placeMark!.thoroughfare != nil) { a1=self.placeMark!.thoroughfare! + "\n" }
                    if (self.placeMark!.postalCode != nil) { a2=self.placeMark!.postalCode! + "\n"}
                    if (self.placeMark!.locality != nil) { a3=self.placeMark!.locality! + "\n"}
                    if (self.placeMark!.country != nil) { a4=self.placeMark!.country! }
                    
                    self.adressLabel.text = a1+a2+a3+a4
                    self.manager.stopUpdatingLocation()
                    self.button.enabled = true
                }
            })
        }
    }
    
  

    @IBAction func buttonPressed(sender: AnyObject) {
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.startUpdatingLocation()
        button.enabled = false
    }

}






















